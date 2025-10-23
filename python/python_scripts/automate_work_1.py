import pyautogui, time

n = int(input("n: "))

time.sleep(7)
for _ in range(n):
    pyautogui.hotkey("ctrl", "v")
    pyautogui.press("enter")
    time.sleep(2)