void setup()
{
  pinMode(2, INPUT); // UltraSonic Sensor Pin
  pinMode(3, OUTPUT); // UltraSonic Sensor Pin
  pinMode(4, INPUT); // UltraSonic Sensor Pin
  pinMode(5, OUTPUT); // UltraSonic Sensor Pin
  
  pinMode(8, OUTPUT); //motor pin
  pinMode(9, OUTPUT); //motor pin
  pinMode(10, OUTPUT); //motor pin
  pinMode(11, OUTPUT); //motor pin

  Serial.begin(9600);
  stop();
}

void stop() // Function to stop all the motors
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backCheck() 
{
  digitalWrite(3, LOW);
  delayMicroseconds(2);

  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  int t1 = pulseIn(2, HIGH);
  int d1 = 0.034 * t1 / 2;
  Serial.println(d1);

  if (d1 < 15)
  {
    stop();
    delay(3000);
  }
}

void check()
{
  digitalWrite(5, LOW);
  delayMicroseconds(2);

  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  int t2 = pulseIn(4, HIGH);
  int d2 = 0.034 * t2 / 2;
  Serial.println(d2);
  
  if (d2 < 15)
  {
    stop();
    delay(3000);
  }
}

void loop()
{
  while (Serial.available())
  {
    char read = Serial.read();
    Serial.println(read);
    check();

    switch (read)
    {
      case 'F' : 
      {
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);
      }
      break;

      case 'B':
      {
        digitalWrite(11, HIGH);
        digitalWrite(9, HIGH);
        backCheck();
      }
      break;

      case 'L': digitalWrite(10, HIGH);
      break;

      case 'R': digitalWrite(8, HIGH);
      break;

      case 'S' : stop();
      break;
    }
  }
}
