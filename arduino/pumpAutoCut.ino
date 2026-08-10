#include <Servo.h>

Servo s;
unsigned long turnOffTime = 390000UL; // 6.5mins = 390000UL
int startPos = 10;

void setup() {
  // put your setup code here, to run once:
  s.attach(9);

  s.write(startPos);
  delay(turnOffTime);
  s.write(60);
  delay(100);
  s.write(startPos);
}

void loop() {
  // put your main code here, to run repeatedly:

}
