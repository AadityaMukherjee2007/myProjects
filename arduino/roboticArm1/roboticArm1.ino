#include <Servo.h>

String in = "";
Servo servo;
int pos = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{
  if (Serial.available())
  {
    in = Serial.readString();
    char motor = in.charAt(0);
    int degree = in.substring(1).toInt();

    Serial.println(motor);
    Serial.println(degree);

    if (degree > pos)
    {
      for (int i = pos; i <= degree; i++)
      {
        servo.write(i);
        delay(15);
      }
    }
    else
    {
      for (int i = pos; i >= degree; i--)
      {
        servo.write(i);
        delay(15);
      }
    }
  }
}
