import io
import webbrowser
from tkinter import *;
from urllib.request import urlopen;
from PIL import ImageTk, Image;
import requests;


class NewsApp:
    def __init__(self):

        # fetch_data
        self.data = requests.get('https://newsapi.org/v2/top-headlines?country=in&apiKey=YOUR-API-KEY').json()
        
        # initial GUI load
        self.load_gui()
        
        # load the 1st news item
        self.load_news_item(0)

    def load_gui(self):
        self.root = Tk()
        self.root.title('News in Short')
        self.root.geometry('340x600')
        self.root.resizable(0,0)
        self.root.configure(background='black')

    def clear(self):
        for i in self.root.pack_slaves():
            i.destroy()

    def load_news_item(self, index):

        #clear screen for the new news items
        self.clear()

        # image
        try:
            img_url = self.data['articles'][index]['urlToImage']
            raw_data = urlopen(img_url).read()
            im = Image.open(io.BytesIO(raw_data)).resize((340,250))
            photo = ImageTk.PhotoImage(im)
        except:
            img_url = 'https://www.hhireb.com/wp-content/uploads/2019/08/default-no-img.jpg';
            raw_data = urlopen(img_url).read()
            im = Image.open(io.BytesIO(raw_data)).resize((340, 250))
            photo = ImageTk.PhotoImage(im)

        label = Label(self.root, image=photo)
        label.pack()

        heading = Label(self.root, text=self.data['articles'][index]['title'], bg='black', fg='white', wraplength=340,
                        justify='center');
        heading.pack(pady=(10, 20))
        heading.config(font=('verdana', 14))

        details = Label(self.root, text=self.data['articles'][index]['description'], bg='black', fg='white', wraplength=340,
                        justify='center');
        details.pack(pady=(10, 20))
        details.config(font=('verdana', 11))

        frame = Frame(self.root, bg='black')
        frame.pack(expand=True, fill=BOTH)

        if index != 0:
            prev = Button(frame, text='Prev', width=16, height=3, fg='#000', bg="#FF5733", command=lambda :self.load_news_item(index-1))
            prev.pack(side=LEFT)

        read = Button(frame, text='Read More', width=16, height=3, fg='#ffffff', bg="#0E6655", command=lambda :self.open_link(self.data['articles'][index]['url']))
        read.pack(side=LEFT)

        if index != len(self.data['articles'])-1:
            next = Button(frame, text='Next', width=16, height=3, fg='#000', bg="#02CDFA", command=lambda :self.load_news_item(index + 1))
            next.pack(side=LEFT)

        self.root.mainloop()

    def open_link(self,url):
        webbrowser.open(url);




obj = NewsApp()
