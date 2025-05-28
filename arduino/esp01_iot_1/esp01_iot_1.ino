#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <WiFiManager.h> 

// wifi manager ip : 192.168.4.1

const int ledPin = 0;

ESP8266WebServer server(80);
bool ledState;
const int eepromAddress = 0;

void saveState() {
  EEPROM.write(eepromAddress, ledState ? 1 : 0);
  EEPROM.commit();
}

void loadState() {
  byte storedValue = EEPROM.read(eepromAddress);
  if (storedValue == 0xFF || storedValue > 1) {
    ledState = false;
    saveState();
  } else {
    ledState = storedValue;
  }
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>";
  html += "body{display:flex;justify-content:center;align-items:center;height:100vh;margin:0;}";
  html += ".btn{padding:20px 40px;font-size:24px;border:none;border-radius:8px;cursor:pointer;";
  html += "background:";
  html += ledState ? "#4CAF50" : "#f44336";
  html += ";color:white;}</style></head><body>";

  if (ledState) {
    html += "<a href='/off'><button class='btn'>OFF</button></a>";
  } else {
    html += "<a href='/on'><button class='btn'>ON</button></a>";
  }

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleOff() {
  ledState = false;
  digitalWrite(ledPin, LOW);  
  saveState();
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOn() {
  ledState = true;
  digitalWrite(ledPin, HIGH);
  saveState();
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  EEPROM.begin(512);
  loadState();

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState ? HIGH : LOW);

  WiFiManager wifiManager;

  // Uncomment to reset saved WiFi credentials (useful for debugging)
  // wifiManager.resetSettings();

  // This will try to connect to saved WiFi
  // If it fails, it starts Access Point with captive portal for config
  if (!wifiManager.autoConnect("ESP_Config_AP")) {
    Serial.println("Failed to connect and hit timeout");
    ESP.restart();  // Restart and try again
  }

  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
