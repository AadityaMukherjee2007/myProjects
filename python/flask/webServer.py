from flask import Flask, request, redirect, render_template
from werkzeug.utils import secure_filename
from markupsafe import escape
import os

app = Flask(__name__)

@app.route('/')
def index():
	return render_template('upload.html')

@app.route('/<name>')
def greet(name):
	return f"Hello, {escape(name)}!"

@app.route('/upload', methods=['GET', 'POST'])
def upload():
	if request.method == 'POST':
		file = request.files['file']
		if file:
			file.save(os.path.join("upload/", secure_filename(file.filename)))
			
		return redirect('/')

if __name__ == "__main__":
	app.run(debug=True)