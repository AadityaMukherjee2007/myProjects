#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() 
{
  Serial.begin(9600);
  compass.init();
}

void loop() 
{
  compass.read();
  int x = compass.getX();
  int y = compass.getY();
  int z = compass.getZ();

  if (x == 0 && y == 0 && z == 0) {
    Serial.println("Error: Magnetometer not responding.");
    delay(1000);
    return;
  }

  int heading = compass.getAzimuth();

  Serial.print("X: "); Serial.print(x);
  Serial.print(" Y: "); Serial.print(y);
  Serial.print(" Z: "); Serial.print(z);
  Serial.print(" Heading: "); Serial.print(heading);
  Serial.print("° ");

  char direction[20] = {0};  // Initialise buffer
  compass.getDirection(direction, heading);
  Serial.println(direction);

  delay(500);
}
