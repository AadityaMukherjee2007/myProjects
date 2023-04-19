from flask import Flask, render_template, request
import sqlite3

con = sqlite3.connect('data.db', check_same_thread=False)
cur = con.cursor()

cur.execute('CREATE TABLE IF NOT EXISTS info(user TEXT, pass TEXT)')
con.commit()

app = Flask(__name__)

@app.route('/signup', methods = ["GET", "POST"])
def signup():
	if request.method == "POST":
		username = request.form['uname']
		password = request.form['passwd']
		if username != None and password != None:
			userInfo = (username, password)
			cur.execute("INSERT INTO info VALUES(?, ?)", userInfo)
			con.commit()
		#else:

	return render_template('signup.html')

@app.route('/login', methods = ["GET", "POST"])
def login():
	if request.method == "POST":
		username = request.form["uname"]
		password = request.form["passwd"]

		print(username + password)
		return username + password
	return render_template('login.html')



if __name__ == '__main__':
	app.run(debug = "True")