int green = 13;
int red = 12;
int yellow = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop()
{
  while (Serial.available())
  {
    char in = Serial.read();
    Serial.println(in);
    
    if (in == '0')
    {
      digitalWrite(green, HIGH);
    }
    else if (in == '1')
    {
      digitalWrite(green, LOW);
    }
    else if (in == '2')
    {
      digitalWrite(red, HIGH);
    }
    else if (in == '3')
    {
      digitalWrite(red, LOW);
    }
    else if (in == '4')
    {
      digitalWrite(yellow, HIGH);
    }
    else if (in == '5')
    {
      digitalWrite(yellow, LOW);
    }
  }
}
