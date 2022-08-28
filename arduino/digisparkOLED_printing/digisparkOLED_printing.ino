#include <Tiny4kOLED.h>

void setup()
{
  oled.begin();
  oled.on();
}

void loop()
{
  oled.clear();
  oled.setFont(FONT6X8P);
  oled.setCursor(10, 10);
  oled.print("Hello, World!");
  delay(10000);
}
