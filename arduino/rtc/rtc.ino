/*
 * Wiring:
 * SDA = A4
 * SCL = A5
 */

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
int power = 13;

void setTime()
{
  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(power, OUTPUT);

  if (! rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  setTime();
  delay(1000);
}

void loop()
{
  DateTime now = rtc.now();

  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());

  if (now.hour() == 10 && now.minute() == 45)
  {
    digitalWrite(power, HIGH);
  }
  else
  {
    digitalWrite(power, LOW);
  }

  Serial.println();
  delay(1000);
}
