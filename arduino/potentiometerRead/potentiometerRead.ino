#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
double read = 0.0;

void setup()
{
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
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
  delay(2000);
}

void loop()
{ 
  read = analogRead(A0);
  Serial.print(read);
  Serial.print("\t\t");
  delay(100);

  double val = (read / 1023) * 100;
  Serial.print(val);
  Serial.println("%");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(50, 5);
  display.print("Load");

  if (val < 10)
  {
    display.setCursor(20, 25);
  }
  else if (val >= 10 && val < 100)
  {
     display.setCursor(10, 25);
  }
  else
  {
    display.setCursor(2, 25);
  }

  display.setTextSize(3);
  display.print(val);
  display.write("%");
  display.display();
}
