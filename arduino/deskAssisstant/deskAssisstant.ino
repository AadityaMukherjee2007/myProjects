#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT.h"

DHT dht(2, DHT11);
RTC_DS3231 rtc;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

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

  display.setCursor(80, 0);
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
  display.setCursor(85, 15);
  display.print(humi);
  display.write("%");

  display.setTextSize(1);
  display.setCursor(90, 38);
  display.print("H.I.");
  display.setCursor(80, 52);
  display.print(heatI);
  display.drawCircle(115, 52, 1, WHITE);
  display.setCursor(119, 52);
  display.print("C");

  display.display();
}

void setup ()
{
  Serial.begin(9600);

  dht.begin();

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
}

void loop ()
{
  for (int i = 1; i <= 5; i++)
  {
    dateTime();
  }

  for (int i = 1; i <= 20; i++)
  {
    weather();
  }
}
