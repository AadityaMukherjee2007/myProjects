/*
 * Wiring:
 * SDA = A4
 * SCL = A5
 */

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

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

  Serial.println();
  delay(1000);
}
