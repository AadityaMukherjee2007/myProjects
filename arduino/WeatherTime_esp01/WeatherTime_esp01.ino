#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Display Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// WiFi & API Settings
const char* wifiSSIDs[] = {"TapeshDuttaRoy", "Tiyasa", "i=q/t#Current"};  
const char* wifiPasswords[] = {"Tapesh@1977", "duttaroy123", "2022#ElectronFlow"};
const int numWiFi = 2;  
const char* API_KEY = "7e2725b04e241d0099a992635554b7c8";
const char* CITY = "Kolkata";
const char* COUNTRY = "IN";
const char* host = "api.openweathermap.org";

// Time Settings (IST Timezone)
const char* weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

WiFiClientSecure client;

// Variables for Storing Data
String weatherCondition = "Loading...";
float temperature = 0.0;
int humidity = 0;
String formattedTime = "00:00";
String formattedDate = "00-00-0000";
String dayOfWeek = "Loading...";

unsigned long lastWeatherUpdate = 0;
unsigned long lastTimeUpdate = 0;
unsigned long lastSwitchTime = 0;
bool showTimeScreen = true;  
int scrollX = 128;  
unsigned long lastScrollTime = 0;  

// Function to Show a Loading Screen
void showLoadingScreen(const String &message) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10, 10);
    display.print(message);
    display.display();
}

// Function to Connect to WiFi
bool connectToWiFi() {
    for (int i = 0; i < numWiFi; i++) {
        showLoadingScreen("Connecting to: " + String(wifiSSIDs[i]));
        
        WiFi.begin(wifiSSIDs[i], wifiPasswords[i]);
        Serial.print("Connecting to WiFi: ");
        Serial.println(wifiSSIDs[i]);

        int attempt = 0;
        while (WiFi.status() != WL_CONNECTED && attempt < 10) {
            delay(500);
            Serial.print(".");
            attempt++;
        }

        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("\n✅ Connected!");
            return true;
        }
        Serial.println("\n❌ Failed! Trying next...");
    }
    return false;  
}

void setup() {
    Serial.begin(115200);
    Wire.begin(0, 2);  

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("❌ OLED not found!");
        while (true);
    }
    Serial.println("✅ OLED Initialized!");

    if (!connectToWiFi()) {
        showLoadingScreen("WiFi Failed!");
        Serial.println("❌ No WiFi Available!");
        while (true);  
    }

    showLoadingScreen("Fetching Time...");
    configTime(19800, 0, "pool.ntp.org", "time.nist.gov");  // Fetch time directly from WiFi
    fetchTime(); 

    showLoadingScreen("Fetching Weather...");
    fetchWeather();

    showLoadingScreen("System Ready!");
    delay(1000);  
}

// Fetch Weather Data (Fixed)
void fetchWeather() {
    Serial.println("\n🌍 Fetching Weather Data...");

    client.setInsecure();  // Ignore SSL certificate errors

    if (!client.connect(host, 443)) {
        Serial.println("❌ Connection to API failed!");
        return;
    }
    Serial.println("✅ Connected to Weather API!");

    // OpenWeatherMap API URL
    String url = "/data/2.5/weather?q=" + String(CITY) + "," + String(COUNTRY) +
                 "&units=metric&appid=" + String(API_KEY);

    Serial.println("🌐 Requesting: " + url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: ESP8266\r\n" +
                 "Accept: application/json\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println("[Waiting for response...]");
    delay(500);

    String payload;
    while (client.connected() || client.available()) {
        if (client.available()) payload += client.readString();
    }
    client.stop();

    if (payload.length() > 0) {
        Serial.println("\n✅ Response Received:");
        Serial.println(payload);
        parseWeatherJSON(payload);
    } else {
        Serial.println("❌ No response received! Check API key or internet connection.");
    }
}

// Parse Weather JSON (Fixed)
void parseWeatherJSON(String jsonString) {
    StaticJsonDocument<1024> doc;
    int jsonStart = jsonString.indexOf('{');

    if (jsonStart == -1) {
        Serial.println("❌ Invalid JSON! No '{' found.");
        return;
    }

    jsonString = jsonString.substring(jsonStart);

    DeserializationError error = deserializeJson(doc, jsonString);
    if (error) {
        Serial.print("❌ JSON parsing failed: ");
        Serial.println(error.c_str());
        return;
    }

    if (!doc.containsKey("weather") || !doc.containsKey("main")) {
        Serial.println("❌ Weather data missing in JSON response!");
        return;
    }

    weatherCondition = doc["weather"][0]["description"].as<String>();
    temperature = doc["main"]["temp"];
    humidity = doc["main"]["humidity"];

    Serial.println("\n✅ Weather Data Updated:");
    Serial.println("🌡 Temperature: " + String(temperature) + "°C");
    Serial.println("💧 Humidity: " + String(humidity) + "%");
    Serial.println("☁ Condition: " + weatherCondition);
}

// Fetch Time Directly from WiFi
void fetchTime() {
    struct tm timeInfo;
    if (!getLocalTime(&timeInfo)) {
        Serial.println("❌ Failed to obtain time!");
        return;
    }

    int day = timeInfo.tm_mday;
    int month = timeInfo.tm_mon + 1;
    int year = timeInfo.tm_year + 1900;
    int weekDayIndex = timeInfo.tm_wday;
    int hour = timeInfo.tm_hour;
    int minute = timeInfo.tm_min;

    formattedDate = (day < 10 ? "0" : "") + String(day) + "-" +
                    (month < 10 ? "0" : "") + String(month) + "-" +
                    String(year);

    formattedTime = (hour < 10 ? "0" : "") + String(hour) + ":" +
                    (minute < 10 ? "0" : "") + String(minute);

    dayOfWeek = weekDays[weekDayIndex];

    Serial.println("✅ Time Fetched: " + formattedTime + " | " + formattedDate);
}

// Display Data on OLED (Fixed Scrolling)
void displayData() {
    static int scrollX = 128;  
    static unsigned long lastScrollTime = 0;

    if (millis() - lastSwitchTime > 15000) {  
        showTimeScreen = !showTimeScreen;
        lastSwitchTime = millis();
        scrollX = 128;  
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    if (showTimeScreen) {
        display.setCursor(10, 0);
        display.print("Date: " + formattedDate);
        display.setCursor(10, 10);
        display.print("Day: " + dayOfWeek);
        display.setCursor(10, 20);
        display.print("Time: " + formattedTime);
    } else {
        display.setCursor(10, 0);
        display.print("Temp: " + String(temperature) + (char)247 + "C");
        display.setCursor(10, 10);
        display.print("Humidity: " + String(humidity) + "%");
        display.setCursor(10, 20);
        display.print(weatherCondition);
    }

    display.display();
}

void loop() {
    if (millis() - lastTimeUpdate > 60000) { fetchTime(); lastTimeUpdate = millis(); }
    if (millis() - lastWeatherUpdate > 900000) { fetchWeather(); lastWeatherUpdate = millis(); }
    displayData();
}
