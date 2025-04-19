#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);       // called this way, it uses the default address 0x40

#define SERVOMIN 100
#define SERVOMAX 600

int currAng[3] = {0};

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);                  // Analog servos run at ~60 Hz updates
}

void loop()
{
  moveServo(0, 0);
  delay(500);
  moveServo(1, 0);
  delay(500);
  moveServo(2, 0);
  delay(500);

  moveServo(0, 90);
  delay(500);
  moveServo(0, 180);
  delay(500);

  moveServo(1, 90);
  delay(500);
  moveServo(1, 180);
  delay(500);

  moveServo(2, 90);
  delay(500);
  moveServo(2, 180);
  delay(500);
  
}

void moveServo(int n, int a)
{
  if (a > currAng[n])
  {
    for (int i = currAng[n]; i <= a; i++)
    {
      pwm.setPWM(n, 0, angleToPulse(i));
      delay(5);
    }
  }
  else
  {
    for (int i = currAng[n]; i >= a; i--)
    {
      pwm.setPWM(n, 0, angleToPulse(i));
      delay(5);
    }
  }
  currAng[n] = a;
}

int angleToPulse(int ang)                             //gets angle in degree and returns the pulse width
{
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // map angle of 0 to 180 to Servo min and Servo max
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}
