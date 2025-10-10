import os
import re
import io
import json
import asyncio
from time import sleep
import requests
import pyautogui as py
import sounddevice as sd
from edge_tts import Communicate
from pydub import AudioSegment
from pydub.playback import play
from vosk import Model, KaldiRecognizer
from fuzzywuzzy import process

# Load Vosk Model
model = Model("vosk-model-en-in-0.5")
rec = KaldiRecognizer(model, 16000)

# App mapping
appmap = {
    "browser": "brave-browser",
    "telegram": "telegram-desktop",
    "email": "mailspring",
    "calculator": "gnome-calculator",
    "vscode": "code",
    "code": "code",
    "text editor": "gedit",
    "text edit": "gedit",
    "arduino": "arduino",
}

apps_terminal = ("htop",)
apps_shortcut = ("terminal",)
apps_search = ("whatsapp", "files", "spotify")

# List of recognised commands
recognised_commands = (
    "jarvis", "minimise", "minimise window", "exit", "exit window", "exit app",
    "close", "close window", "close app", "open", "press", "light", "fan",
    "auto tile", "switch keyboard layout", "show system process", "type text",
    "lock screen", "lock session", "system shutdown", "volume up", "volume down",
    "volume mute", "volume unmute"
)

# Async TTS
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

# App launching helpers
def open_using_shortcut(app_name):
    if app_name == "terminal":
        py.hotkey("win", "t")

def open_using_search(app_name):
    py.press("win")
    py.write(app_name)
    sleep(1)
    py.press("enter")

def open_using_terminal(app_name):
    py.hotkey("win", "t")
    sleep(0.5)
    py.write(app_name)
    py.press("enter")

def get_caps_lock():
    s = os.popen('xset -q').read()
    return bool(re.search('Caps Lock:\\s+on', s))

def open_app(app_name):
    if app_name in apps_shortcut:
        open_using_shortcut(app_name)
    elif app_name in apps_search:
        open_using_search(app_name)
    elif app_name in apps_terminal:
        open_using_terminal(app_name)
    else:
        if get_caps_lock():
            py.press("capslock")
        py.hotkey("alt", "f2")
        py.write(appmap.get(app_name, ""))
        py.press("enter")

# Voice input processing
def listen():
    with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16', channels=1) as stream:
        print("🎙️ Listening...")
        while True:
            data, _ = stream.read(4000)
            if rec.AcceptWaveform(bytes(data)):
                result = json.loads(rec.Result())
                return clean_command(result["text"])

def clean_command(cmd):
    cmd = cmd.lower().strip()
    cmd = re.sub(r"[^a-z0-9\s]", "", cmd)
    cmd = re.sub(r"\s+", " ", cmd)
    return cmd

def match_command(input_cmd, commands, threshold=80):
    match, score = process.extractOne(input_cmd, commands)
    return match if score >= threshold else None

# Main logic
def main():
    while True:
        command = listen()
        matched = match_command(command, recognised_commands)
        if not matched:
            continue

        if matched == "jarvis":
            reply("All systems active! How can I help you?")

        elif matched == "system shutdown":
            reply("Shutting down system.")
            open_using_shortcut("terminal")
            sleep(1)
            py.write("sudo systemctl poweroff")
            py.press("enter")
            py.write("Pop#2025")  # Replace with actual sudo password securely if needed
            py.press("enter")

        elif matched in ("lock screen", "lock session"):
            py.hotkey("win", "esc")

        elif matched == "auto tile":
            reply("Toggling auto tile.")
            py.hotkey("win", "y")

        elif matched == "switch keyboard layout":
            py.hotkey("win", "space")
            reply("Keyboard layout switched.")

        elif matched == "show system process":
            reply("Opening system processes.")
            open_app("htop")

        elif matched.startswith("volume"):
            if "up" in command:
                os.system("amixer set Master 10%+")
                reply("Volume up.")
            elif "down" in command:
                os.system("amixer set Master 10%-")
                reply("Volume down.")
            elif "mute" in command:
                os.system("amixer set Master mute")
                reply("Volume muted.")
            elif "unmute" in command:
                os.system("amixer set Master unmute")
                reply("Volume unmuted.")

        elif matched in ("minimise", "minimise window"):
            py.hotkey("win", "h")

        elif matched in ("exit", "exit window", "exit app", "close", "close window", "close app"):
            py.hotkey("alt", "f4")

        elif command.startswith("open"):
            try:
                _, app_name = command.split(" ", 1)
                reply(f"Opening {app_name}")
                open_app(app_name)
            except ValueError:
                reply("Please specify an app to open.")

        elif command.startswith("light"):
            if "on" in command:
                requests.get("http://192.168.0.161/on")
                reply("Light turned on.")
            elif "off" in command:
                requests.get("http://192.168.0.161/off")
                reply("Light turned off.")

        elif command.startswith("fan"):
            if "on" in command:
                requests.get("http://192.168.0.189/on")
                reply("Fan turned on.")
            elif "off" in command:
                requests.get("http://192.168.0.189/off")
                reply("Fan turned off.")

        elif command.startswith("type text"):
            text = command.replace("type text", "").strip()
            py.write(text)

        elif command.startswith("press"):
            key = command.replace("press", "").strip()
            py.press(key)

if __name__ == "__main__":
    main()

