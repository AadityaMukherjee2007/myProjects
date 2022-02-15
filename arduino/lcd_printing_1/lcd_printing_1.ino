#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() 
{
  lcd.init();

  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Hello");
}

void loop() 
{
  
}
