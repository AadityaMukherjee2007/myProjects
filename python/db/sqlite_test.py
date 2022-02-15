import sqlite3 as sq

con = sq.connect('studentInfo.db')
cur = con.cursor()

"""
cur.execute('''CREATE TABLE "info" (
                    "Student Name" TEXT,
                    "Class" INTEGER,
                    "Section" TEXT,
                    "Roll" INTEGER
                );''')"""

info = ()

x = str(input("Enter Data? [Y/n] : "))
x = x.lower()

if x == "y":
    name = input("Enter Student Name: ")
    Class = int(input("Enter Class: "))
    sec = input("Enter Section: ")
    roll = int(input("Enter Roll Number: "))
    info = (name, Class, sec, roll)

    ch = input("Enter Data in DataBase? [Y/n] : ")
    ch = ch.lower()

    if ch == "y":
        cur.execute('INSERT INTO "info" VALUES (?, ?, ?, ?)', info)
        con.commit()

m = input("Print Data? [Y/n] : ")
m = m.lower()

if m == "y":
    for i in cur.execute("SELECT * FROM info"):
        print(i)
