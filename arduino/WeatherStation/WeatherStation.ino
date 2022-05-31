#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT.h"

DHT dht(2, DHT11);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

float temp, hmd, heatIndex;

void temperature()
{
  temp = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 5);
  display.print("Temperature");
  
  display.setCursor(20, 25);
  display.setTextSize(2);
  display.print(temp);
  display.drawCircle(85, 25, 2, WHITE);
  display.setCursor(89, 25);
  display.write("C");
  display.display();
}

void humidity()
{
  hmd = dht.readHumidity();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(40, 5);
  display.print("Humidity");
  
  display.setCursor(25, 25);
  display.setTextSize(2);
  display.print(hmd);
  display.write("%");
  display.display();
}



void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  dht.begin();
/*
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 25);
  display.print("Loading");
  for (int i = 1; i <= 3; i++)
  {
    delay(350);
    display.print(".");
    display.display();
  }
  delay(2000);*/
}

void loop()
{
  temperature();
  delay(3000);
  humidity();
  delay(3000);
}
