#include <Servo.h>
Servo servo1;
int d1 = 1000;
int longD = 43200000; 
/*For feeding the fish after 12 hrs, set the value of longD to 43200000...
  For feeding the fish after 24 hrs, set the value of longD to 86400000...
*/
 
void setup() {
  servo1.attach(9);
}
 
void loop() {
  servo1.write(180);
  delay(d1);
  servo1.write(0);
  delay(d1);
  servo1.write(180);
  delay(d1);
  servo1.write(0);
  delay(d1);
  servo1.write(180);
  delay(43200000);
}
