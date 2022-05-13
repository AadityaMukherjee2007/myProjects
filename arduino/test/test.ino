int led = 13;
void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop()
{
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}
