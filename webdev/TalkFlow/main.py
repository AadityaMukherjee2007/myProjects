from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods = ["GET", "POST"])
def index():
	if request.method == "POST":
		username = request.form.get("uname")
		password = request.form.get("passwd")

		print(username + password)
		return username + password
	return render_template('index.html')



if __name__ == '__main__':
	app.run(debug = "True")