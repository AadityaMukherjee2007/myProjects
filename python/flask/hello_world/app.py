from flask import Flask, jsonify
import random

app = Flask(__name__)

@app.route('/')
def index():
    return "Hello, World!"

@app.route('/random')
def getnum():
    return jsonify({
        "num": random.randint(0, 9)
    })

if __name__ == '__main__':
    app.run(debug=True)