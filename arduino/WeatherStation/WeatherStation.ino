#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT.h"

DHT dht(2, DHT11);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void Display(float tc, float tf,int h, float hi)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("Temperature");
  display.setCursor(80, 0);
  display.print("Humidity");

  display.setCursor(10, 22);
  display.print(tc);
  display.drawCircle(45, 22, 1, WHITE);
  display.setCursor(49, 22);
  display.write("C");
  display.setCursor(10, 42);
  display.print(tf);
  display.drawCircle(45, 42, 1, WHITE);
  display.setCursor(49, 42);
  display.write("F");

  display.setTextSize(2);
  display.setCursor(85, 15);
  display.print(h);
  display.write("%");

  display.setTextSize(1);
  display.setCursor(90, 38);
  display.print("H.I.");
  display.setCursor(80, 52);
  display.print(hi);
  display.drawCircle(115, 52, 1, WHITE);
  display.setCursor(119, 52);
  display.print("C");

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

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 5);
  display.print("Weather");
  display.setCursor(22, 33);
  display.print("Station");
  display.display();
  delay(3000);
}

void loop()
{
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  int humi = dht.readHumidity();
  float heatI = dht.computeHeatIndex(tempC, humi, false);
  Display(tempC, tempF, humi, heatI);
}
