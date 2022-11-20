#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT.h"

DHT dht(2, DHT11);
RTC_DS3231 rtc;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
int mode = 13, c = 0;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void dateTime()
{
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 25);
  if (now.hour() < 10)
  {
    display.write("0");
  }
  display.print(now.hour());
  display.write(":");
  if (now.minute() < 10)
  {
    display.write("0");
  }
  display.print(now.minute());
  display.write(":");
  if (now.second() < 10)
  {
    display.write("0");
  }
  display.print(now.second());

  display.setCursor(0, 0);
  display.setTextSize(1);
  if (now.day() < 10)
  {
    display.write("0");
  }
  display.print(now.day(), DEC);
  display.write("/");
  if (now.month() < 10)
  {
    display.write("0");
  }
  display.print(now.month(), DEC);
  display.write("/");
  display.print(now.year(), DEC);
  
  switch(now.dayOfTheWeek())
  {
    case 0 : 
    case 1 : display.setCursor(92, 0);
    break;
    case 2 : display.setCursor(86, 0);
    break;
    case 3 : display.setCursor(74, 0);
    break;
    case 4 : display.setCursor(80, 0);
    break;
    case 5 : display.setCursor(92, 0);
    break;
    case 6 : display.setCursor(80, 0);
    break;
  }
  
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);

  display.display();

  Serial.println();
  delay(1000);
}

void weather()
{
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  int humi = dht.readHumidity();
  float heatI = dht.computeHeatIndex(tempC, humi, false);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Temperature");
  display.setCursor(80, 0);
  display.print("Humidity");

  display.setCursor(10, 22);
  display.print(tempC);
  display.drawCircle(45, 22, 1, WHITE);
  display.setCursor(49, 22);
  display.write("C");
  display.setCursor(10, 42);
  display.print(tempF);
  display.drawCircle(45, 42, 1, WHITE);
  display.setCursor(49, 42);
  display.write("F");

  display.setTextSize(2);
  display.setCursor(86, 16);
  display.print(humi);
  display.write("%");

  display.setTextSize(1);
  display.setCursor(91, 39);
  display.print("H.I.");
  display.setCursor(80, 53);
  display.print(heatI);
  display.drawCircle(115, 53, 1, WHITE);
  display.setCursor(119, 53);
  display.print("C");

  display.display();
  delay(250);
}

void phoneInfo()
{
  String charge = Serial.readString();
  Serial.println(charge);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30, 30);
  display.print(charge);
  display.write("%");
  display.drawRect(30, 30, 50, 25, WHITE);
  display.drawRect(79, 37, 5, 10, WHITE);
  display.display();
}

void setup ()
{
  Serial.begin(9600);
  pinMode(mode, INPUT);
  dht.begin();
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
}

void loop ()
{
  Serial.println(digitalRead(mode));
  if (!digitalRead(mode))
  {
    if (c == 0)
    {
      c = 1;
    }
    else
    {
      c = 0;
    }
  }
  
  if (c == 1)
  {
    weather();
  }
  else
  {
    dateTime();
  }
}
