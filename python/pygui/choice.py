import tkinter as tk

main = tk.Tk()
main.geometry("300x200")
main.title("Quiz")
main.resizable(False, False)

x = ""

var = ""

def show():
	fLabel = tk.Label(main, text = var.get()).pack()

q1 = tk.Label(main, text = "Q1)  (45 + 3) / 2 = ?").place(x = 10, y = 10)
q1op1 = tk.Checkbutton(main, text = "24", variable = var, onvalue = "on", offvalue = "off").place(x = 10, y = 40)
q1op2 = tk.Checkbutton(main, text = "12").place(x = 60, y = 40)
q1op3 = tk.Checkbutton(main, text = "6").place(x = 110, y = 40)
q1op4 = tk.Checkbutton(main, text = "28").place(x = 160, y = 40)

conBut = tk.Button(main, text = "Submit", command = show).place(x = 210, y = 155)

main.mainloop()