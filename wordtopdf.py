from docx2pdf import convert;

try:
    print("\n-------Word To PDF Converter-------\n")
    inputDocx = input("Enter the Word file Name to Convert to PDF: ")
    outputPDF = input("Enter the filename to save PDF: ")

    # convert(inputDocx)
    # convert("test.docx")
    convert(inputDocx + ".docx", outputPDF + ".pdf")
    print("Successful!!!!!\n")

except:
    print("\nSomething went wrong\n")
