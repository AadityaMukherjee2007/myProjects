import speech_recognition, asyncio, io, requests
import pyautogui as py
from edge_tts import Communicate
from pydub import AudioSegment
from pydub.playback import play

appmap = {
    "browser": "brave-browser", 
    "telegram": "telegram-desktop", 
    "email": "mailspring", 
    "calculator": "gnome-calculator", 
    "vscode": "code", 
    "code": "code", 
    "text editor": "gedit",
    "text edit": "gedit"
}

apps_terminal = ("htop")

apps_shortcut = ("terminal")

apps_search = ("whatsapp", "files")

# tuple of recognised commands
recognised_commands = (
    "jarvis", 
    "minimise", 
    "minimise window", 
    "exit", 
    "exit window", 
    "exit app", 
    "close", 
    "close window", 
    "close app", 
    "open", 
    "press", 
    "light", 
    "auto tile",
    "switch keyboard layout", 
    "show system process", 
    "type text"
)

recogniser = speech_recognition.Recognizer()


async def speak(text):
    communicate = Communicate(text, voice="en-GB-RyanNeural")
    audio_data = bytearray()

    async for chunk in communicate.stream():
        if chunk["type"] == "audio":
            audio_data.extend(chunk["data"])

    audio = AudioSegment.from_file(io.BytesIO(audio_data), format="mp3")
    play(audio)


def reply(text):
    asyncio.run(speak(text))


def open_using_shortcut(app_name):
    if app_name == "terminal":
        py.hotkey("win", "t")
        
    

def open_using_search(app_name):
    py.press("win")
    py.write(app_name)
    py.press("enter")
     

def open_using_terminal(app_name):
    py.hotkey("win", "t")
    py.write(app_name)
    py.press("enter")


def open(app_name):
    if app_name in apps_shortcut:
        open_using_shortcut(app_name)
    elif app_name in apps_search:
        open_using_search(app_name)
    elif app_name in apps_terminal:
        open_using_terminal(app_name)
    else:
        py.hotkey("alt", "f2")
        py.write(appmap[app_name])
        py.press("enter")
     


def main():
    while True:
        try:
            with speech_recognition.Microphone() as mic:
                print("Listening...")

                recogniser.adjust_for_ambient_noise(mic, duration=0.5)
                audio = recogniser.listen(mic)

                command = recogniser.recognize_google(audio)
                command = command.lower().strip()
                print("Recognised: " + command)


            if not any(cmd in command for cmd in recognised_commands):
                continue

            
            if command == "jarvis":
                reply("All systems active! How can i help you?")


            if command == "auto tile":
                reply("Toggling auto tile")
                py.hotkey("win", "y")

            # to switch keyboard layout
            if command == "switch keyboard layout":
                reply("Switching keyboard layout")
                py.hotkey("win", "space")

            if command == "show system process":
                reply("Opening system proccesses")
                open("htop")

            # to minimise the current window or app
            if command in ["minimise", "minimise window"]:
                py.hotkey("win", "h")

            # to close or exit the current app or window
            if command in ["exit window", "exit app", "close window", "close app"]:
                py.hotkey("alt", "f4")

            # to open desktop apps
            if command.startswith("open"):
                try:
                    _, app_name = command.split(" ", 1)
                except ValueError:
                    continue

                if (
                    app_name not in appmap and
                    app_name not in apps_search and
                    app_name not in apps_shortcut and
                    app_name not in apps_terminal
                ):
                    reply("Unable to open app")
                    continue


                reply(f"Opening {app_name}")
                open(app_name)

            # to control tubelight of my room
            if command.startswith("light"):
                try:
                    _, state = command.split(" ")
                except ValueError:
                    continue

                if state in ["on", "off", "toggle"]:
                    requests.get("http://192.168.0.161/toggle")
                else:
                    continue

            if command.startswith("type text"):
                txt = command[9:]
                py.write(txt)

            if command.startswith("press"):
                key = command[6:]
                py.press(key)



        except speech_recognition.UnknownValueError:
            print("Sorry, I didn't catch that.")
            continue
            # reply("Sorry, I didn't catch that.")


if __name__ == "__main__":
    main()
