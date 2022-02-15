#define trigPin 2
#define echoPin 3

// 1 sec = 1000000 microseconds
double s = (340 * 100) / 1000000;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println("cm");
  
}
