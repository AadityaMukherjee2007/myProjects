import sqlite3 as sq
import tkinter as tk

con = sq.connect("StudentData.db")
cur = con.cursor()

cur.execute('CREATE TABLE IF NOT EXISTS info("Student Name" TEXT, Age INTEGER, Gender, "Blood Type" TEXT)')

txt = ""

def commit():
	if nameIn.get() != "" and ageIn.get() != "" and genderIn.get() != "" and bloodTypeIn.get() != "":
		check = [nameIn.get().upper()]
		cur.execute('SELECT Age, Gender, "Blood Type" FROM info WHERE "Student Name" = ?', check)
		if cur.fetchall():
			txt = "Student is already registered\nwith the database."
			conWarL.config(text = txt, fg = "red")
		else:
			StdData = (nameIn.get().upper(), int(ageIn.get()), genderIn.get().upper(), bloodTypeIn.get().upper())
			cur.execute('INSERT INTO info VALUES(?, ?, ?, ?)', StdData)
			con.commit()
			txt = "Registration Successful."
			conWarL.config(text = txt, fg = "green")
	else:
		txt = "Please enter all the\nrequired fields."
		conWarL.config(text = txt, fg = "red")



main = tk.Tk()
main.geometry("300x200")
main.title("Admission")

main.resizable(False, False)

name = tk.Label(main, text = "Student Name: ")
nameIn = tk.Entry(main)

age = tk.Label(main, text = "Age: ")
ageIn = tk.Entry(main)

gender = tk.Label(main, text = "Gender: ")
genderIn = tk.Entry(main)

bloodType = tk.Label(main, text = "Blood Type: ")
bloodTypeIn = tk.Entry(main)

conWarL = tk.Label(main, text = txt, fg = "red")

enterDataB = tk.Button(main, text = "Enter Data", command = commit)

name.place(x = 10, y = 10)
nameIn.place(x = 120, y = 10)
age.place(x = 10, y = 40)
ageIn.place(x = 120, y = 40)
gender.place(x = 10, y = 70)
genderIn.place(x = 120, y = 70)
bloodType.place(x = 10, y = 100)
bloodTypeIn.place(x = 120, y = 100)
conWarL.place(x = 10, y = 140)
enterDataB.place(x = 195, y = 160)

main.mainloop()

cur.close()
con.close()