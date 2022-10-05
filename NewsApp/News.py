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
        # print(data)
        # initial GUI load
        self.load_gui()
        # self.root.mainloop()
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
