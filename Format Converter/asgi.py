from app import app  # Import your FastAPI app instance from main.py

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("asgi:app", host="127.0.0.1", port=8000, reload=True)

# Export ASGI app callable for server use
# app = app