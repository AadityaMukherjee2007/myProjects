#include <Adafruit_SSD1306.h>
#include <Wire.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
int mode = 1;

void d3()
{
  int read1 = 0, read2 = 0, read3 = 0;
  read1 = analogRead(A0);
  read2 = analogRead(A1);
  read3 = analogRead(A2);

  float v1 = read1 * (5.0 / 1023.0);
  float v2 = read2 * (5.0 / 1023.0);
  float v3 = read3 * (5.0 / 1023.0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.print("Volatge (1) : ");
  display.print(v1);
  display.write("v");
  display.setCursor(0, 25);
  display.print("Volatge (2) : ");
  display.print(v2);
  display.write("v");
  display.setCursor(0, 45);
  display.print("Volatge (3) : ");
  display.print(v3);
  display.write("v");
  display.display();
}

void d2()
{
  int read1 = 0, read2 = 0;
  read1 = analogRead(A0);
  read2 = analogRead(A1);

  float v1 = read1 * (5.0 / 1023.0);
  float v2 = read2 * (5.0 / 1023.0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.print("Volatge (1) : ");
  display.print(v1);
  display.write("v");
  display.setCursor(0, 25);
  display.print("Volatge (2) : ");
  display.print(v2);
  display.write("v");
  display.display();
}

void d1()
{
  int read1 = 0;
  read1 = analogRead(A0);

  float v1 = read1 * (5.0 / 1023.0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.print("Volatge (1) : ");
  display.print(v1);
  display.write("v");
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

  pinMode(2, INPUT);
}

void loop()
{
  d1();
}
