from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/talkflow/login')
def index():
	return render_template('index.html')

@app.route('/checkCredentials', methods=['GET', 'POST'])
def checkCredentials():
	print("checking credentials...")

if __name__ == '__main__':
	app.run(debug = "True")