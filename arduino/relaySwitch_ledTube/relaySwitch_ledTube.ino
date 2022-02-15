#include "RTClib.h"

int power = 7;
RTC_DS3231 rtc;

void setup()
{
  Serial.begin(9600);
  pinMode(power, OUTPUT);

  rtc.begin();
}

void loop()
{
  DateTime now = rtc.now();

  if ((now.hour() >= 15 && now.minute() >= 3) && (now.hour() <= 16 && now.minute() < 48))
  {
    digitalWrite(power, HIGH);
  }
  else if (false)
  {

  }
  else
  {
    digitalWrite(power, LOW);
  }
}
