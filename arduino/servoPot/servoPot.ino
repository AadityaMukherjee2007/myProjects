#include <Servo.h>

Servo servo;
void setup()
{
  servo.attach(9);
  Serial.begin(9600);
  servo.write(0);
}

void loop()
{
  int value = analogRead(0);
  Serial.println(value);
  value = map(value, 0, 1023, 0, 180);
  Serial.println(value);
  servo.write(value);
  delay(500);
}
