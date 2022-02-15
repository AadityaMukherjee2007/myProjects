import tkinter as tk

main = tk.Tk()

def click():
    label = tk.Label(main, text = "Hello, World")
    label.pack()

"""
b = tk.Button(main, text = "Click Me!", state = "normal")  
 
state enables you to control the state of the widget. 
Eg: state = "disabled" //means it won't work
states can be "disabled", "active" or "normal" 
"""

# b = tk.Button(main, text = "Click me!", padx = 50, pady = 30) # pad is used to increase the size

b = tk.Button(main, text = "Click me!", command = click, fg = "#ffffff", bg = "orange")
# when using command, don't give parenthesis while calling a function
# fg is used for setting color in text
# bg is used for setting background color
# you can us ehex color codes too!

b.pack()

chkb = tk.Checkbutton(main, text = "Python", command = print("Python is Chosen!"))
chkb.pack()

main.mainloop()
