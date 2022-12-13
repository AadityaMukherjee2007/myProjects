from tkinter import *

def main():
	def addTodo():	
		task = todo.get()
		if task != "":
			Label(root, text=task).grid(row=x)
			todo.set("")
			x += 1

	root = Tk()
	root.title("TODO App")
	root.resizable(False, False)
	root.geometry("250x200")
	todo=StringVar()
	entry = Entry(root, textvariable=todo).grid(row = 0, column = 0, pady = 10, padx = 10)
	add = Button(root, text="Add", command=addTodo).grid(row = 0, column = 1)
	mainloop()


main()

#working on var x... to add new tasks