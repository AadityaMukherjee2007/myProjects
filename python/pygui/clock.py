from tkinter import Tk, Label
from time import strftime

window = Tk()
window.title("Clock")

label = Label(window, font=("Arial", 50), background="black", foreground="cyan")
label.pack(anchor="center")

def Update():
    currentTime = strftime("%H:%M:%S")
    label.config(text=currentTime)
    label.after(1000, Update)

Update()
window.mainloop()