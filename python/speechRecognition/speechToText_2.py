import sounddevice as sd
import requests, sys, json, queue
from vosk import Model, KaldiRecognizer

phrases = '["on", "off", "toggle"]'

q = queue.Queue()

# 🧠 Audio callback: feeds audio chunks to a queue
def callback(indata, frames, time, status):
    if status:
        print(status, file=sys.stderr)
    q.put(bytes(indata))

# 🗣️ Load model
model = Model("model")

recogniser = KaldiRecognizer(model, 16000, phrases)

# 🎤 Open microphone stream
with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype='int16',
                       channels=1, callback=callback):
    print("🎙️ Say something...")

    while True:
        data = q.get()
        if recogniser.AcceptWaveform(data):
            result = json.loads(recogniser.Result())
            text = result.get("text", "").lower()
            print(f"📝 You said: {text}")

            # 🔘 Simple LED command logic
            if text == "on":
                requests.get("http://192.168.0.161/on")
            elif text == "off":
                requests.get("http://192.168.0.161/off")