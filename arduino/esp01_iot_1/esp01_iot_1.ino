const char* ssid = "i=q/t#Current";
const char* password = "2022#ElectronFlow";

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

const int ledPin = 0; 

ESP8266WebServer server(80);
bool ledState;
const int eepromAddress = 0;

void saveState() {
  EEPROM.put(eepromAddress, ledState);
  EEPROM.commit();
}

void loadState() {
  EEPROM.get(eepromAddress, ledState);
  if (EEPROM.read(eepromAddress) > 1) {
    ledState = false;
    saveState();
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
  html += ";color:white;}</style></head>";
  html += "<body><a href='/toggle'><button class='btn'>";
  html += ledState ? "ON" : "OFF";
  html += "</button></a></body></html>";
  
  server.send(200, "text/html", html);
}

void handleToggle() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState ? LOW : HIGH);
  saveState();
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  EEPROM.begin(512);
  loadState();
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState ? LOW : HIGH);
  
  WiFi.begin(ssid, password);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  while (WiFi.status() != WL_CONNECTED) delay(10);
  
  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

void loop() {
  server.handleClient();
}
