import sqlite3 as sq

con = sq.connect("loginData.db")
cur = con.cursor()

for x in cur.execute("SELECT * FROM usrPasswd"):
    print(x)