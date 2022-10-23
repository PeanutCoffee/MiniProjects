########################################## Attendfolio ##########################################

import tkinter as tk
from tkinter import Tk, ttk
from tkinter import messagebox as mess
import tkinter.simpledialog as tsd
import cv2, os 
import csv
import numpy as np
from PIL import Image
import pandas as pd
import datetime
import time

########################################## FUNCTIONS ##########################################

def assure_path_exists(path):
    dir = os.path.dirname(path)
    if not os.path.exists(dir):
        os.makedirs(dir)

########################################## Time ##########################################

def tick():
    time_string = time.strftime('Time: %H:%M:%S')
    clock.config(text=time_string)
    clock.after(300,tick)

########################################## Contact Us ##########################################

def contact():
    mess._show(title='Contact us', message="Get in Touch : amruthasriamaravati852@gmail.com ")

########################################## Wqrning ##########################################

def check_haarcascadefile():
    exists= os.path.isfile("haarcascade_frontalface_default.xml")
    if exists:
        pass
    else:
        mess._show(title='Some files are missing', message='Please contact us for help')
        window.destroy()

########################################## Save Password ##########################################

def save_pass():
    assure_path_exists("TrainingImageLabel/")
    exists1 = os.path.isfile("TrainingImageLabel\psd.txt")
    if exists1:
        tf = open("TrainingImageLabel\psd.txt", "r")
        key = tf.read()
    else:
        master.destroy()
        new_pas = tsd.askstring('Old Password not found', 'Please enter a new password below', show='*')
        if new_pas == None:
            mess._show(title='No Password Entered', message='Password not set!! Please try again')
        else:
            tf = open("TrainingImageLabel\psd.txt", "w")
            tf.write(new_pas)
            mess._show(title='Password Registered', message='New password registered successfully!!')
            return
    op = (old.get())
    newp= (new.get())
    nnewp = (nnew.get())
    if (op == key):
        if(newp == nnewp):
            txf = open("TrainingImageLabel\psd.txt", "w")
            txf.write(newp)
        else:
            mess._show(title='Error', message='Confirm new password again!!!')
            return
    else:
        mess._show(title='Wrong Password', message='Please enter correct old password.')
        return
    mess._show(title='Password Changed', message='Password changed successfully!!')
    master.destroy()

########################################## Change Password ##########################################

def change_pass():
    global master
    master = tk.Tk()
    master.geometry("400x160")
    master.resizable(False,False)
    master.title("Change Password")
    master.configure(background="white")
    lbl4 = tk.Label(master,text='Current Password',bg='white',font=('arial', 10, ' bold '))
    lbl4.place(x=10,y=10)
    global old
    old=tk.Entry(master,width=25 ,fg="black",relief='solid',font=('arial', 11, ' normal '),show='*')
    old.place(x=180,y=10)
    lbl5 = tk.Label(master, text='New Password', bg='white', font=('arial', 10, ' bold '))
    lbl5.place(x=10, y=45)
    global new
    new = tk.Entry(master, width=25, fg="black",relief='solid', font=('arial', 11, ' normal '),show='*')
    new.place(x=180, y=45)
    lbl6 = tk.Label(master, text='Confirm New Password', bg='white', font=('arial', 10, ' bold '))
    lbl6.place(x=10, y=80)  #alignment
    global nnew
    nnew = tk.Entry(master, width=25, fg="black", relief='solid',font=('arial', 11, ' normal '),show='*')
    nnew.place(x=180, y=80)

    save1 = tk.Button(master, text="Update Password", relief='groove',command=save_pass, 
    fg="black", bg="#0ec772", height = 1,width=50, activebackground="white", font=('arial', 9, ' bold '))

    save1.place(x=20, y=120)
    master.mainloop()

########################################## Password ##########################################

def psw():
    assure_path_exists("TrainingImageLabel/")
    exists1 = os.path.isfile("TrainingImageLabel\psd.txt")
    if exists1:
        tf = open("TrainingImageLabel\psd.txt", "r")
        key = tf.read()
    else:
        new_pas = tsd.askstring('Old Password not found', 'Please enter a new password below', show='*')
        if new_pas == None:
            mess._show(title='No Password Entered', message='Password not set!! Please try again')
        else:
            tf = open("TrainingImageLabel\psd.txt", "w")
            tf.write(new_pas)
            mess._show(title='Password Registered', message='New password was registered successfully!!')
            return
    password = tsd.askstring('Password', 'Enter Password', show='*')
    if (password == key):
        TrainImages()
    elif (password == None):
        pass
    else:
        mess._show(title='Wrong Password', message='You have entered wrong password')

########################################## Clear Option ##########################################

def clear():
    txt.delete(0, 'end')
    res = "Enter your details and Scan your images and then Submit!"
    message1.configure(text=res)


def clear2():
    txt2.delete(0, 'end')
    res = "Enter your details and Scan your images and then Submit!"
    message1.configure(text=res)

########################################## Scan ##########################################

def TakeImages():
    check_haarcascadefile()
    columns = ['SERIAL NO.', '', 'ID', '', 'NAME']
    assure_path_exists("StudentDetails/")
    assure_path_exists("TrainingImage/")
    serial = 0
    exists = os.path.isfile("StudentDetails\StudentDetails.csv")
    if exists:
        with open("StudentDetails\StudentDetails.csv", 'r') as csvFile1:
            reader1 = csv.reader(csvFile1)
            for l in reader1:
                serial = serial + 1
        serial = (serial // 2)
        csvFile1.close()
    else:
        with open("StudentDetails\StudentDetails.csv", 'a+') as csvFile1:
            writer = csv.writer(csvFile1)
            writer.writerow(columns)
            serial = 1
        csvFile1.close()
    Id = (txt.get())
    name = (txt2.get())
    if ((name.isalpha()) or (' ' in name)):
        cam = cv2.VideoCapture(0)
        harcascadePath = "haarcascade_frontalface_default.xml"
        detector = cv2.CascadeClassifier(harcascadePath)
        sampleNum = 0
        while (True):
            ret, img = cam.read()
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            faces = detector.detectMultiScale(gray, 1.3, 5)
            for (x, y, w, h) in faces:
                cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
                # incrementing sample number
                sampleNum = sampleNum + 1
                # saving the captured face in the dataset folder TrainingImage
                cv2.imwrite("TrainingImage\ " +"_"+ name + "." + str(serial) + "." + Id + '.' + str(sampleNum) + ".jpg",
                            gray[y:y + h, x:x + w])
                # display the frame
                cv2.imshow('Taking Images', img)
            # wait for 100 miliseconds
            if cv2.waitKey(100) & 0xFF == ord('q'):
                break
            # break if the sample number is morethan 100
            elif sampleNum > 100:
                break
        cam.release()
        cv2.destroyAllWindows()
        res = "Images Taken for ID : " + Id
        row = [serial, '', Id, '', name]
        with open('StudentDetails\StudentDetails.csv', 'a+') as csvFile:
            writer = csv.writer(csvFile)
            writer.writerow(row)
        csvFile.close()
        message1.configure(text=res)
    else:
        if (name.isalpha() == False):
            res = "Enter Correct name"
            message.configure(text=res)

########################################## ##########################################

def TrainImages():
    check_haarcascadefile()
    assure_path_exists("TrainingImageLabel/")
    
    recognizer = cv2.face_LBPHFaceRecognizer.create()

    harcascadePath = "haarcascade_frontalface_default.xml"
    detector = cv2.CascadeClassifier(harcascadePath)
    faces, ID = getImagesAndLabels("TrainingImage")
    try:
        recognizer.train(faces, np.array(ID))
    except:
        mess._show(title='No Registrations', message='Please Register someone first!!!')
        return
    recognizer.save("TrainingImageLabel\Trainner.yml")
    res = "Profile Saved Successfully"
    message1.configure(text=res)
    message.configure(text='Response(s)  : ' + str(ID[0]))

########################################## ##########################################

def getImagesAndLabels(path):
    # get the path of all the files in the folder
    imagePaths = [os.path.join(path, f) for f in os.listdir(path)]
    # create empth face list
    faces = []
    # create empty ID list
    Ids = []
    # now looping through all the image paths and loading the Ids and the images
    for imagePath in imagePaths:
        # loading the image and converting it to gray scale
        pilImage = Image.open(imagePath).convert('L')
        # Now we are converting the PIL image into numpy array
        imageNp = np.array(pilImage, 'uint8')
        # getting the Id from the image
        ID = int(os.path.split(imagePath)[-1].split(".")[1])
        # extract the face from the training image sample
        faces.append(imageNp)
        Ids.append(ID)
    return faces, Ids

####################################################################################

def TrackImages():
    check_haarcascadefile()
    assure_path_exists("Attendance/")
    assure_path_exists("StudentDetails/")
    for k in tv.get_children():
        tv.delete(k)
    msg = ''
    i = 0
    j = 0

    recognizer = cv2.face.LBPHFaceRecognizer_create()   #cv2.createLBPHFaceRecognizer()

    exists3 = os.path.isfile("TrainingImageLabel\Trainner.yml")
    if exists3:
        recognizer.read("TrainingImageLabel\Trainner.yml")
    else:
        mess._show(title='Data Missing', message='Please click on Save Profile to reset data!!')
        return
    harcascadePath = "haarcascade_frontalface_default.xml"
    faceCascade = cv2.CascadeClassifier(harcascadePath)

    cam = cv2.VideoCapture(0)
    font = cv2.FONT_HERSHEY_SIMPLEX
    col_names = ['Id', '', 'Name', '', 'Date', '', 'Time']
    exists1 = os.path.isfile("StudentDetails\StudentDetails.csv")
    if exists1:
        df = pd.read_csv("StudentDetails\StudentDetails.csv")
    else:
        mess._show(title='Details Missing', message='Students details are missing, please check...')
        cam.release()
        cv2.destroyAllWindows()
        window.destroy()
    while True:
        ret, im = cam.read()
        gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
        faces = faceCascade.detectMultiScale(gray, 1.2, 5)
        for (x, y, w, h) in faces:
            cv2.rectangle(im, (x, y), (x + w, y + h), (225, 0, 0), 2)
            serial, conf = recognizer.predict(gray[y:y + h, x:x + w])
            if (conf < 50):
                ts = time.time()
                date = datetime.datetime.fromtimestamp(ts).strftime('%d-%m-%Y')
                timeStamp = datetime.datetime.fromtimestamp(ts).strftime('%H:%M:%S')
                aa = df.loc[df['SERIAL NO.'] == serial]['NAME'].values
                ID = df.loc[df['SERIAL NO.'] == serial]['ID'].values
                ID = str(ID)
                ID = ID[1:-1]
                bb = str(aa)
                bb = bb[2:-2]
                attendance = [str(ID), '', bb, '', str(date), '', str(timeStamp)]

            else:
                Id = 'Unknown'
                bb = str(Id)
            cv2.putText(im, str(bb), (x, y + h), font, 1, (255, 255, 255), 2)
        cv2.imshow('Taking Attendance', im)
        if (cv2.waitKey(1) == ord('q')):
            break
    ts = time.time()
    date = datetime.datetime.fromtimestamp(ts).strftime('%d-%m-%Y')
    exists = os.path.isfile("Attendance\Attendance_" + date + ".csv")
    if exists:
        with open("Attendance\Attendance_" + date + ".csv", 'a+') as csvFile1:
            writer = csv.writer(csvFile1)
            writer.writerow(attendance)
        csvFile1.close()
    else:
        with open("Attendance\Attendance_" + date + ".csv", 'a+') as csvFile1:
            writer = csv.writer(csvFile1)
            writer.writerow(col_names)
            writer.writerow(attendance)
        csvFile1.close()
    with open("Attendance\Attendance_" + date + ".csv", 'r') as csvFile1:
        reader1 = csv.reader(csvFile1)
        for lines in reader1:
            i = i + 1
            if (i > 1):
                if (i % 2 != 0):
                    iidd = str(lines[0]) + '   '
                    tv.insert('', 0, text=iidd, values=(str(lines[2]), str(lines[4]), str(lines[6])))
    csvFile1.close()
    cam.release()
    cv2.destroyAllWindows()

########################################## Date ##########################################
    
global key
key = ''

ts = time.time()
date = datetime.datetime.fromtimestamp(ts).strftime('Date: %d-%m-%Y')
day,month,year=date.split("-")

mont={
      
      '01':'January',
      '02':'February',
      '03':'March',
      '04':'April',
      '05':'May',
      '06':'June',
      '07':'July',
      '08':'August',
      '09':'September',
      '10':'October',
      '11':'November',
      '12':'December'
      }

########################################## GUI FRONT-END ##########################################

window = tk.Tk()
window.geometry("1920x1080")
window.resizable(True,False)
window.title("Attendfolio")
window.configure(background='#0ACDDC') 


frame1 = tk.Frame(window, bg="#E6EFF6") #Make ur attendance
frame1.place(relx=0.11, rely=0.17, relwidth=0.39, relheight=0.80)

frame2 = tk.Frame(window, bg="#E6EFF6") #Fill in your Details 
frame2.place(relx=0.51, rely=0.17, relwidth=0.38, relheight=0.80)

message3 = tk.Label(window, text="TRACK ATTENDANCE USING FACE RECOGNITION" ,
fg="White",bg="#0ACDDC" ,width=50 ,height=1,font=('Microsoft New Tai Lue', 30, ' bold '))

message3.place(x=40, y=10)

frame3 = tk.Frame(window, bg="#E6EFF6")
frame3.place(relx=0.52, rely=0.09, relwidth=0.09, relheight=0.07)

frame4 = tk.Frame(window, bg="#E6EFF6")
frame4.place(relx=0.36, rely=0.09, relwidth=0.16, relheight=0.07)

datef = tk.Label(frame4, text = day+ "-" +mont[month]+ "-" +year+"   | " , 
fg="#3d4141",bg="#0acddc" ,width=60 ,height=1,font=('candara', 15, ' bold '))

datef.pack(fill='both',expand=1)

clock = tk.Label(frame3,fg="#3d4141",bg="#0acddc" ,width=120 ,height=1,font=('candara', 14, ' bold '))
clock.pack(fill='both',expand=1)
tick()

head2 = tk.Label(frame2, text="Register", fg="black",bg="#e6eff6" ,font=('Arial', 17, ' bold ') )
head2.place(x=200,y=20)

lbl = tk.Label(frame2, text="Enrollment ID*", width=12,bg="#E6EFF6" , fg="#828f8f",font=('Arial', 12, ' bold '))  
lbl.place(x=20, y=65)

txt = tk.Entry(frame2,width=31 ,fg="black",font=('Arial', 15, ' normal '))  #The Text Box 1
txt.place(x=30, y=88)

lbl2 = tk.Label(frame2, text="Full Name*",width=12, bg="#E6EFF6"  ,fg="#828f8f" ,font=('Arial', 12, ' bold '))
lbl2.place(x=9, y=150)

txt2 = tk.Entry(frame2,width=31 ,fg="black",font=('arial', 15, ' normal ')  ) #The Text Box 2
txt2.place(x=30, y=173)

message1 = tk.Label(frame2, 
text="Guide: Welcome! To Register for the Attendance.\nPlease Fill in your Details, Click on Scan & then Submit!" ,
bg="#e6eff6" ,fg="#3d4141"  ,width=0 ,height=2,font=('Arial', 10, ' bold '))

message1.place(x=45, y=230) 


message = tk.Label(frame2, text="" ,bg="#e6eff6" ,fg="#3d4141"  ,width=39,height=1,font=('Arial', 15, ' bold '))
message.place(x=10, y=445) #Responses

lbl3 = tk.Label(frame1, text="Attendfolio",width=20  ,fg="#00adba"  ,
bg="#e6eff6"  ,height=1 ,font=('Microsoft New Tai Lue', 30, 'bold'))

lbl3.place(x=5, y=80)

res=0
exists = os.path.isfile("StudentDetails\StudentDetails.csv")
if exists:
    with open("StudentDetails\StudentDetails.csv", 'r') as csvFile1:
        reader1 = csv.reader(csvFile1)
        for l in reader1:
            res = res + 1
    res = (res // 2) - 1
    csvFile1.close()
else:
    res = 0
message.configure(text='Response(s) : '+str(res))


########################################## MENUBAR ##########################################

menubar = tk.Menu(window,relief='groove')
filemenu = tk.Menu(menubar,tearoff=0)
menubar.add_cascade(label='Change Password', command = change_pass)
menubar.add_cascade(label='Need Help?',font=('arial', 25, ' normal '), menu=filemenu)
filemenu.add_command(label='Contact Us', command = contact)
filemenu.add_command(label='Exit',command = window.destroy)


########################################## TREEVIEW ATTENDANCE TABLE ##########################################

tv= ttk.Treeview(frame1,height =13,columns = ('name','date','time'))
tv.column('#0',width=82)
tv.column('name',width=130)
tv.column('date',width=133)
tv.column('time',width=133)
tv.grid(row=2,column=0,padx=(0,0),pady=(150,0),columnspan=4)
tv.heading('#0',text ='ID')
tv.heading('name',text ='NAME')
tv.heading('date',text ='DATE')
tv.heading('time',text ='TIME')

########################################## SCROLLBAR ##########################################

scroll=ttk.Scrollbar(frame1,orient='vertical',command=tv.yview)
scroll.grid(row=2,column=4,padx=(0,100),pady=(150,0),sticky='ns')
tv.configure(yscrollcommand=scroll.set)

########################################## BUTTONS ##########################################

clearButton=tk.Button(frame2,text="Clear",relief='groove',command=clear,fg="#3d4141",bg="#ECB42D",width=11,activebackground="yellow",font=('arial',12,'normal'))
clearButton.place(x=335, y=86)
clearButton2=tk.Button(frame2,text="Clear",relief='groove',command=clear2 ,fg="#3d4141",bg="#ECB42D",width=11,activebackground="orange",font=('arial',12, 'normal'))
clearButton2.place(x=335, y=172)    
takeImages=tk.Button(frame2,text="Scan",command=TakeImages,fg="white",bg="#50a5fc",width=34,height=1,activebackground="blue",font=('arial', 15, 'bold'))
takeImages.place(x=30, y=300)
trainImages=tk.Button(frame2,text="Submit",command=psw ,fg="white",bg="#0ec772",width=34,height=1,activebackground="green",font=('arial', 15, 'bold'))
trainImages.place(x=30, y=370)
trackImages=tk.Button(frame1,text="Take Attendance",command=TrackImages,fg="black",bg="#0ec772",width=35,height=1,activebackground="green",font=('comic',15,'bold'))
trackImages.place(x=30,y=20)
quitWindow=tk.Button(frame1,text="Quit",command=window.destroy,fg="black",bg="#ec2d51",width=35,height=1,activebackground="red",font=('arial',15,'bold'))
quitWindow.place(x=30, y=450)

########################################## END ##########################################

window.configure(menu=menubar)
window.mainloop()
