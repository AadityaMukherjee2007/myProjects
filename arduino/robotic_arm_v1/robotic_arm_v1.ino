#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a PCA9685 object with default I2C address (0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVO_MIN  150  // Min pulse length (0°)
#define SERVO_MAX  600  // Max pulse length (180°)
#define SERVO_CHANNEL  0 // Servo connected to PCA9685 Channel 0

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50); // Set frequency to 50Hz for servos
}

void loop() {
  Serial.println("Moving Servo to 0°");
  pwm.setPWM(SERVO_CHANNEL, 0, SERVO_MIN);
  delay(1000);

  Serial.println("Moving Servo to 90°");
  pwm.setPWM(SERVO_CHANNEL, 0, (SERVO_MIN + SERVO_MAX) / 2);
  delay(1000);

  Serial.println("Moving Servo to 180°");
  pwm.setPWM(SERVO_CHANNEL, 0, SERVO_MAX);
  delay(1000);
}
