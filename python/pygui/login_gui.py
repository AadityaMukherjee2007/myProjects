import tkinter as tk
import sqlite3 as sq

con = sq.connect("Login.db")
cur = con.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS username(Username TEXT, Password TEXT)")
x = ""

def commit():
	user = [usrIn.get()]
	cur.execute("SELECT Password FROM username WHERE Username = ?", user)
	if cur.fetchall():
		x = "Username already taken.\nPlease choose another one"
		finalL.config(text = x, fg = "red")

def check():
	logData = [user.get(), passwd.get()]
	cur.execute("SELECT * FROM username WHERE Username = ? AND Password = ?", logData)
	if cur.fetchall():
		x = "Login Successful!"
		finalL.config(text = x, fg = "green")
	
		


def register():
	reg = tk.Tk()
	reg.title("Register")
	reg.geometry('330x160')

	reg.resizable(False, False)

	usrL = tk.Label(reg, text = "Username: ")
	usrIn = tk.Entry(reg)

	pass1L = tk.Label(reg, text = "Password: ")
	pass1In = tk.Entry(reg, show = "*")

	pass2L = tk.Label(reg, text = "Rewrite Password: ")
	pass2In = tk.Entry(reg, show = "*")

	regB = tk.Button(reg, text = "Register", command = commit)

	finalL = tk.Label(reg, text = x)

	usrL.place(x = 10, y =  10)
	usrIn.place(x = 140, y = 10)
	pass1L.place(x = 10, y = 40)
	pass1In.place(x = 140, y = 40)
	pass2L.place(x = 10, y = 70)
	pass2In.place(x = 140, y = 70)
	regB.place(x = 240, y = 120)
	finalL.place(x = 20, y = 110)

	reg.mainloop()


def main():
	main = tk.Tk()
	main.title("Login")
	main.geometry('300x140')

	main.resizable(False, False)

	userL = tk.Label(main, text = "Username: ")
	user = tk.Entry(main)

	passwdL = tk.Label(main, text = "Password: ")
	passwd = tk.Entry(main, show = "*")

	loginB = tk.Button(main, text = "Login", padx = 25)
	registerB = tk.Button(main, text = "Register", padx = 15, command = register)

	userL.place(x = 10, y =  10)
	user.place(x = 100, y = 10)
	passwdL.place(x = 10, y = 40)
	passwd.place(x = 100, y = 40)
	loginB.place(x = 200, y = 100)
	registerB.place(x = 10, y = 100)

	main.mainloop()



main()
cur.close()
con.close()
