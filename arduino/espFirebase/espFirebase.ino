#include <WiFi.h>
#include <FirebaseESP32.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include <DHT.h>

#define API_KEY "<API_KEY>"
#define DATABASE_URL "<DATABASE_URL>"

DHT dht(14, DHT11);

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

bool signupOk = false;
unsigned long elapsedMillis = 0;
int updateInterval = 2000;
int c = 0;

void wifi()
{
    WiFi.begin("<WIFI_SSID>", "<PASSWORD>");
    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nConnected!");
}

void firebase_connect()
{
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.reconnectWiFi(true);

  if (Firebase.signUp(&config, &auth, "", ""))
  {
    signupOk = true; 
  }
  else
  {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);

  if (Firebase.ready())
    Serial.println("Firebase is ready...");
  else
  {
    Serial.println("Firebase is not ready...");
    //exit(0);
  }
}

void uploadData()
{
  if (millis() - elapsedMillis > updateInterval && signupOk && Firebase.ready())
  {
    elapsedMillis = millis();

    String t = String(dht.readTemperature()) + "°C";
    String h = String((int) dht.readHumidity()) + "%";
    
    Firebase.setString(fbdo, "/Weather/Temperature", t);
    Firebase.setString(fbdo, "/Weather/Humidity", h);
  }
}

void setup()
{
  Serial.begin(115200);
  dht.begin();
  wifi();
  firebase_connect();
  
}

void loop()
{
  uploadData();
}
  
