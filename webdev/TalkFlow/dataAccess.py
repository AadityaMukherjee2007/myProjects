import sqlite3

con = sqlite3.connect('data.db')
cur = con.cursor()
"""
cur.execute('''
	INSERT INTO info VALUES
		("hello", "PASS"),
		("adi", "PASS")
	''')"""

userInfo = ("adi", "hello")
cur.execute("INSERT INTO info VALUES(?, ?)", userInfo)

cur.execute("DELETE FROM info")

con.commit()

for data in cur.execute("SELECT user, pass FROM info"):
	print(data)