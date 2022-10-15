#install pillow library first  by running this command in terminal 
# pip install pillow

# import pillow and tkinter 
import PIL
from PIL import Image
from tkinter.filedialog import *

# take image input from user 

file_path = askopenfilename()

# compress the input image  

Image = PIL.Image.open(file_path)
height, width = Image.size
Img = Image.resize((height,width), PIL.Image.ANTIALIAS)
save_path = asksaveasfilename()

# save the file in specified path  

Img.save(save_path+”Img.jpeg”)
