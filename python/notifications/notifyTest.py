from notifypy import Notify

notification = Notify()
notification.title = "Test"
notification.message = "Hello, World!"
notification.audio = "./not_1.wav"

notification.send()
