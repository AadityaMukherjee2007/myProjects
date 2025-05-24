import speech_recognition, asyncio, io 
import pyautogui as py
from edge_tts import Communicate
from pydub import AudioSegment
from pydub.playback import play

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

def open(app_name):
    appmap = {
        "browser": "brave-browser"
    }

    py.hotkey("alt", "f2")
    py.write(appmap[app_name])
    py.press("enter")

def main():
    while True:
        try:
            with speech_recognition.Microphone() as mic:
                print("Listening...")

                recogniser.adjust_for_ambient_noise(mic, duration=0.2)
                audio = recogniser.listen(mic)

                command = recogniser.recognize_google(audio)
                command = command.lower().strip()
                print("Recognised: " + command)

                if command == "jarvis":
                    reply("All systems active!")
                
                if command.startswith("open"):
                    _, app = command.split(" ")
                    print(app)
                    reply("Opening default browser")
                    open(app)

                    
        except speech_recognition.UnknownValueError:
            print("Sorry, I didn't catch that.")
            reply("Sorry, I didn't catch that.")    


if __name__ == "__main__":
    main()