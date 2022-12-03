#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define trigPin 2
#define echoPin 3
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// 1 sec = 1000000 microseconds
double s = (340 * 100) / 1000000;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  double t = pulseIn(echoPin, HIGH);
  double d = 0.034 * t / 2;

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 25);
  display.print(d);
  display.write("cm");
  display.display();

  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println("cm");
  delay(500);
}
