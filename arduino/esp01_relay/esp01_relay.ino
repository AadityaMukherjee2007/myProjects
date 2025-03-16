#define BLYNK_TEMPLATE_ID "TMPL3VUgSKEg4"
#define BLYNK_TEMPLATE_NAME "tube"
#define BLYNK_AUTH_TOKEN "nX6EMEIwhbnRbY6iVuvLGIq4xjNr0oXT"  // Correct variable name

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const char* ssid = "i=q/t#Current";
const char* password = "2022#ElectronFlow";

BlynkTimer timer;
const int relayPin = 2;  // GPIO2

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);  // Corrected variable name
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Relay OFF (Active Low)
}

void loop() {
  Blynk.run();  // Keeps Blynk connected
}
