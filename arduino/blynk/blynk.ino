//Activates communication between the Blynk App and Serial Monitor:
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>  //Import a "ESP8266_Lib" library.
#include <BlynkSimpleESP8266.h> //Import a "BlynkSimpleShieldEsp8266" library.
#define BLYNK_TEMPLATE_ID "TMPL3VUgSKEg4"
#define BLYNK_TEMPLATE_NAME "tube"
#define BLYNK_AUTH_TOKEN "nX6EMEIwhbnRbY6iVuvLGIq4xjNr0oXT"
//Authentication of account in the Blynk App.
char auth[] = BLYNK_AUTH_TOKEN;  //Enter the device's auth token code.

//Enter the WiFi credentials.
char ssid[] = "i=q/t#Current";//Name of the Wi-Fi network.
char pass[] = "2022#ElectronFlow"; //Wi-Fi network password.
  //Note: Set password to "" for open Wi-Fi networks.

//Run the SETUP function only once after pressing Reset:
void setup() {
  //Starts Communication Serial:
  Serial.begin(9600);
  
  //Starts Wi-Fi communication:
  Blynk.begin(auth, ssid, pass);
}

//Run the LOOP function repeatedly.:
void loop() {
  //Starts communication with the Blynk App:
  Blynk.run();

  //Place the remaining code for your project.
} 
