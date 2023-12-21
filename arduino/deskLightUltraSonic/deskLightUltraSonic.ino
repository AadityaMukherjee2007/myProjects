                                              /*
Desk Ultrasonic Switch
*/
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

const int trigPin = 9;
const int echoPin = 10;

int state = 0;

const int relay = 4;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);

  digitalWrite(relay, 0);
  
  Serial.begin(9600);
}

int proximity()
{
  int distance;
  long duration;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void loop() 
{
  Serial.println(proximity());
  if (proximity() < 30)
  {
    if (state == 0)
    {
      state = 1;
    }
    else
    {
      state = 0;
    }
  }

  digitalWrite(relay, state);

  delay(250);
}
