import pyautogui, time

msg = input("Message: ")
n = int(input("n: "))

print("Spamming in 5 secs :)")
time.sleep(5)

for _ in range(n):
    pyautogui.write(msg)
    pyautogui.press("enter")
