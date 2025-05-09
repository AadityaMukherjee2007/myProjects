from fastapi import FastAPI
from fastapi.params import Body

app = FastAPI()

@app.get('/')
def root():
    return {"message": "Hello, World"}

@app.get('/posts')
def get_posts():
    return {"data": "This is your post"}

@app.post('/createposts')
def create_posts(payLoad: dict=Body(...)):
    print(payLoad)
    # return {"message": "Successfully created post"}
    return {"new_post": f"title: {payLoad['title']} content: {payLoad['content']}"}