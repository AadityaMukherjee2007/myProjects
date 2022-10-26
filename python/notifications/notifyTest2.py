import time
from plyer import notification
from playsound import playsound

if __name__ == "__main__":
	while True:
		notification.notify(
			title = "Test",
			message = "Hello, World",
			timeout = 2
		)
		playsound("./not_1.wav")
		time.sleep(60)
