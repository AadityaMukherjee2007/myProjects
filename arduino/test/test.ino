
int buzzer = 11;
void beep()
{
  digitalWrite(buzzer, HIGH);
  delay(150);
  digitalWrite(buzzer, LOW);
  delay(150);
}
void setup()
{
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop()
{
  //beep();
}
