#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

//https://console.firebase.google.com/u/0/project/data-1-36f9b/database/data-1-36f9b-default-rtdb/data/~2F

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define DEVICE_UID "esp32"

#define ssid "i=q/t#Current"
#define passwd "2022#ElectronFlow"

#define API_KEY "AIzaSyC5LZu0mE7jnKer2IQG_muKF8VconlcQOk"
#define DATABASE_URL "https://data-1-36f9b-default-rtdb.asia-southeast1.firebasedatabase.app/"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long elapsedMillis = 0;
long update_interval = 5000;
int count = 0;
bool isAuthenticated = false;
String fuid = "", device_location = "Home";

void Wifi_Init()
{
    WiFi.begin(ssid, passwd);
    Serial.print("Connection to Wifi");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }

    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
}

void firebase_init()
{
    config.api_key = API_KEY;
    config.database_url = DATABASE_URL;
    Firebase.reconnectWiFi(true);

    Serial.println("--------------------------------");
    Serial.println("Sign up new user...");

    if (Firebase.signUp(&config, &auth, "", ""))
    {
        Serial.println("Success");
        isAuthenticated = true;
        fuid = auth.token.uid.c_str();
    }
    else
    {
        Serial.printf("Failed, %s\n", config.signer.signupError.message.c_str());
        isAuthenticated = false;
    }

    config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&config, &auth);
}

void databaseTest()
{
    if (millis() - elapsedMillis > update_interval && isAuthenticated && Firebase.ready())
    {
        elapsedMillis = millis();
        Serial.println("------------------------------------------");
        Serial.println("Set int test...");
        String node = "/data/value";

        if (Firebase.set(fbdo, node.c_str(), count++))
        {
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println("ETag: " + fbdo.ETag());
            Serial.print("VALUE: ");
            printResult(fbdo);
            Serial.println("------------------------------------");
            Serial.println();
        }
        else
        {
            Serial.println("FAILED");
            Serial.println("REASON: " + fbdo.errorReason());
            Serial.println("------------------------------------");
            Serial.println();
        }
    }
}

void setup()
{
    Serial.begin(115200);
    Wifi_Init();
    firebase_init();
}

void loop()
{
    databaseTest();
}