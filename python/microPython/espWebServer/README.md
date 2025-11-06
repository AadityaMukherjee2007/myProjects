# 💡 IoT Web Server – ESP8266 Home Automation

### Overview
This project demonstrates how to control electronic devices over a **local network** using an **ESP8266** microcontroller and **MicroPython**.  
I’ve hosted a **web server** directly on the ESP8266 that lets me control a **4-channel relay module** through an interactive HTML interface — allowing real-time toggling of devices like lights or fans from any browser connected to the same network.

Currently, I’ve connected it to my **desk light**, but the setup can handle up to **four independent devices**.

---

### ⚙️ Features
- Web-based control panel (responsive HTML interface)  
- Supports up to 4 relays for device control  
- Real-time device state updates (ON/OFF)  
- Built entirely using **MicroPython**  
- Runs on local Wi-Fi (no external cloud dependency)  
- Easily expandable for smart home automation

---

### 🧠 Tech Stack
- **Microcontroller:** ESP8266  
- **Language:** MicroPython  
- **Web Interface:** HTML + CSS + Basic JavaScript  
- **Relay Driver:** 4-Channel Relay Module  
- **Network:** Local Wi-Fi server  

---

### 🪜 How It Works
1. The ESP8266 connects to your local Wi-Fi network using credentials from `boot.py`.  
2. A web server is initialized that serves a simple HTML dashboard.  
3. Each button on the interface triggers GPIO signals via the relay driver.  
4. The connected devices toggle ON/OFF in real-time.  

---

### 🧩 Files
- **`boot.py`** – Handles Wi-Fi setup and GPIO pin initialization.  
- **`main.py`** – Manages web server logic, device control, and UI rendering.  

---

### 📸 Demo
(Add screenshots or short GIF of the UI here)

---

### 🚀 Future Improvements
- Add MQTT support for cloud-based control  
- Build a mobile app interface  
- Implement user authentication for network security  

---

### 🧰 Hardware Used
- ESP8266 NodeMCU  
- 4-Channel Relay Module  
- Jumper Wires  
- Power Supply (5V)  
- Desk Light (for demonstration)  

---

### 🤝 Contribute
Feel free to fork this repo, open issues, or suggest improvements.  
If you build your own version, tag me — I’d love to see your take on it.

---

### 📬 Author
**Aaditya Mukherjee**  
Tech enthusiast | IoT & Automation | Data Science | Solopreneur  
[LinkedIn](https://www.linkedin.com/in/aaditya-mukherjee-4490182b7/) • [Portfolio](https://aadityamukherjee2007.github.io/)
