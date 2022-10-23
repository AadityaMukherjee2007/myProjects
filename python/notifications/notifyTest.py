from notifypy import Notify

notification = Notify()
notification.title = "Test"
notification.message = "Hello, World!"
notification.audio = "/home/linux/Documents/myProjects/python/notifications/not_1.wav"

notification.send()