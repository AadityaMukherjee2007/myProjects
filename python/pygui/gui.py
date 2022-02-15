from tkinter import *
win = Tk()

myLabel1 = Label(win, text = "Hello, World!").grid(row = 0, column = 0)

myLabel2 = Label(win, text = "Python is cool!")
myLabel2.grid(row = 1, column = 5)

win.mainloop()
