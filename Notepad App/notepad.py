#Notepad mede by Ankush Mallick
#Made by python tkinter module

from tkinter import *
import tkinter.messagebox as tmsg
from tkinter.filedialog import askopenfilename,asksaveasfilename
import os
root =Tk()
root.geometry("700x700")
root.title("Notepad made by Ankush Mallick")
root.wm_iconbitmap('2.ico')

def newfile():
    global file
    root.title("Untitled-Notepad made by Ankush Mallick")
    file = None
    text.delete(1.0,END)

def openfile():
    global file
    file = askopenfilename(defaultextension='.txt',filetypes=[('All Files','*.*'),('text documents','*.txt')])
    if file == "":
        file = None
    else:
        root.title(os.path.basename(file) + "-Notepad made by Ankush Mallick")
        text.delete(1.0,END)
        f=(open,"r")
        text.insert(1.0,f.read())
        f.close()

def savefile():
    global file
    if file == None:
        file = askopenfilename(initialfile='Untitled.txt',defaultextension='.txt',filetypes=[('All Files','*.*'),('text documents','*.txt')])
        if file == "":
            file = None
        else:
            f = open(file,'w')
            f.write(text.get(1.0,END))
            f.close()
            root.title(os.path.basename(file) + "-Notepad made by Ankush Mallick")
    else:
        f = open(file,'w')
        f.write(text.get(1.0,END))
        f.close()

def exit_notepad():
    root.destroy()

def cut():
    text.event_generate(("<<Cut>>"))
def copy():
    text.event_generate(("<<Copy>>"))

def paste():
    text.event_generate(("<<Paste>>"))

def info():
    tmsg.showinfo('Information','This notepad was made by me,Ankush Mallick.\nThnak you.')

def feedback():
    a = tmsg.askyesno('Feedback','Are you satisfied using notepad?')
    print(a)
text = Text(root,font='lucida 14')
text.pack(expand='true',fill='both')
file =None

menubar = Menu(root)
filemenu = Menu(menubar,tearoff = 0)
filemenu.add_command(label="New", command = newfile)
filemenu.add_command(label="Open", command = openfile)
filemenu.add_command(label="Save", command = savefile)
filemenu.add_separator()
filemenu.add_command(label="Exit", command = exit_notepad)
menubar.add_cascade(label='File',menu=filemenu)

editmenu = Menu(menubar,tearoff = 0)
editmenu.add_command(label="Cut", command = cut)
editmenu.add_command(label="Copy", command = copy)
editmenu.add_command(label="Paste", command = paste)
menubar.add_cascade(label='Edit',menu=editmenu)

helpmenu = Menu(menubar,tearoff = 0)
helpmenu.add_command(label="Info", command = info)
helpmenu.add_command(label="Send feedback", command = feedback)
menubar.add_cascade(label='Help',menu=helpmenu)
root.config(menu=menubar)

scroll =Scrollbar(text)
scroll.pack(side=RIGHT,fill='y')
scroll.config(command=text.yview)
text.config(yscrollcommand=scroll.set)
root.mainloop()