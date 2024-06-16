int m1f = 7, m1b = 6, m2f = 4, m2b = 5;

int arr[] = {m1f, m1b, m2f, m2b};

void forward()
{
  digitalWrite(m1f, HIGH);
  digitalWrite(m2f, HIGH);
}

void backward()
{
  digitalWrite(m1b, HIGH);
  digitalWrite(m2b, HIGH);
}

void left()
{
  digitalWrite(m1f, HIGH);
  digitalWrite(m2f, LOW);
}

void right()
{
  digitalWrite(m1f, LOW);
  digitalWrite(m2f, HIGH);
}

void stop()
{
  digitalWrite(m1f, LOW);
  digitalWrite(m2f, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2b, LOW);
}


void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(arr[i], OUTPUT);
    digitalWrite(arr[i], LOW);
  }
  Serial.begin(9600);
  stop();
}

void loop()
{
  while (Serial.available())
  {
      char in = Serial.read();
      Serial.println(in);

      switch (in)
      {
        case 'F': forward();
        break;
        case 'B': backward();
        break;
        case 'R': right();
        break;
        case 'L': left();
        break;
        case 'S': stop();
        break;
      }
  }
}
