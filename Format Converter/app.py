from fastapi import FastAPI, UploadFile, File, Form, HTTPException
from fastapi.responses import StreamingResponse, JSONResponse
import io, os
import markdown, pdfkit
from docx import Document
from bs4 import BeautifulSoup
import pypandoc
from pdfminer.high_level import extract_text
from fastapi.responses import FileResponse
import tempfile

app = FastAPI()

SUPPORTED_FORMATS = ["markdown", "html", "pdf", "docx", "json"]

def detect_format(filename: str) -> str:
    ext = os.path.splitext(filename)[1].lower()
    ext_map = {
        '.md': 'markdown', '.markdown': 'markdown',
        '.html': 'html', '.htm': 'html',
        '.pdf': 'pdf',
        '.docx': 'docx',
        '.json': 'json'
    }
    return ext_map.get(ext, '')

def md_to_html(md_text: str) -> bytes:
    return markdown.markdown(md_text).encode()

def md_to_docx(md_text: str) -> bytes:
    with tempfile.NamedTemporaryFile(delete=False, suffix='.docx') as tmp_file:
        output_path = tmp_file.name
    try:
        pypandoc.convert_text(md_text, 'docx', format='md', outputfile=output_path)
        with open(output_path, 'rb') as f:
            docx_bytes = f.read()
    finally:
        os.remove(output_path)
    return docx_bytes

def md_to_json(md_text: str) -> dict:
    segments = [seg.strip() for seg in md_text.split('\n\n') if seg.strip()]
    return {"segments": segments}

def md_to_pdf(md_text: str) -> bytes:
    html = markdown.markdown(md_text)
    config = pdfkit.configuration(wkhtmltopdf="C:\\Program Files\\wkhtmltopdf\\bin\\wkhtmltopdf.exe")
    return pdfkit.from_string(html, False, configuration=config)

CONVERSION_MAP = {
    ('markdown', 'html'): md_to_html,
    ('markdown', 'pdf'): md_to_pdf,
    ('markdown', 'docx'): md_to_docx,
    ('markdown', 'json'): md_to_json,
    # ('html', 'markdown'): html_to_md,
    # ('html', 'pdf'): html_to_pdf,
    # ('html', 'docx'): html_to_docx,
    # ('docx', 'markdown'): docx_to_md,
    # ('pdf', 'json'): pdf_to_json,
    # ('pdf', 'markdown'): pdf_to_md,
}

@app.post("/convert")
async def convert_document(file: UploadFile = File(...), target_format: str = Form(...), download: bool = Form(False)):
    if target_format not in SUPPORTED_FORMATS:
        raise HTTPException(400, "Unsupported target format")

    source_format = detect_format(file.filename)
    if not source_format:
        raise HTTPException(400, "Cannot detect source format")

    converter = CONVERSION_MAP.get((source_format, target_format))
    if not converter:
        raise HTTPException(501, f"Conversion from {source_format} to {target_format} not supported")

    input_bytes = await file.read()
    if source_format in ['markdown', 'html']:
        result = converter(input_bytes.decode())
    else:
        result = converter(input_bytes)

    if target_format == 'json':
        return JSONResponse(result)

    mime_types = {
        'markdown': 'text/markdown',
        'html': 'text/html',
        'pdf': 'application/pdf',
        'docx': 'application/vnd.openxmlformats-officedocument.wordprocessingml.document',
    }

    if download:
        # Create suffix for file extension
        suffix_map = {
            'markdown': '.md',
            'html': '.html',
            'pdf': '.pdf',
            'docx': '.docx',
        }
        suffix = suffix_map.get(target_format, '')

        # Use tempfile to create a temp file
        with tempfile.NamedTemporaryFile(delete=False, suffix=suffix) as tmp:
            tmp.write(result)
            tmp_path = tmp.name
        
        return FileResponse(
            tmp_path,
            media_type=mime_types.get(target_format, 'application/octet-stream'),
            filename=f"converted{suffix}",
            background=None
        )
    
    media_type = mime_types.get(target_format, 'application/octet-stream')
    return StreamingResponse(io.BytesIO(result), media_type=media_type)
