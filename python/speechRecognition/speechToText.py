import sounddevice as sd
from scipy.io.wavfile import write
import whisper
import requests

def record(duration=5):
    fs = 44100
    print("🎙️ Recording...")
    audio = sd.rec(int(duration * fs), samplerate=fs, channels=1, dtype='int16')
    sd.wait()
    print("✅ Done recording.")

    write("output.wav", fs, audio)
    print("📁 Saved as output.wav")

def transcribe(model):
    result = model.transcribe("output.wav")
    print(f"📝 Transcription: {result['text']}")
    return result["text"].lower()

def led_toggle():
    url = "http://192.168.0.161/toggle"
    response = requests.get(url)
    if response.status_code == 200:
        print("🔆 LED toggled!")
    else:
        print(f"⚠️ Failed to toggle LED: {response.status_code}")

def main():
    model = whisper.load_model("base")  # Load once outside the loop for speed
    while True:
        record(duration=5)  # shorter recording for faster response
        command = transcribe(model)
        if any(word in command for word in ["on", "off", "toggle"]):
            led_toggle()

if __name__ == "__main__":
    main()
