int PIC_IN = 10;
int LED = 13;


void setup()
{
  Serial.begin(9600);
  pinMode(PIC_IN, INPUT);

  digitalWrite(LED, LOW);
}

void loop()
{
  int val = digitalRead(PIC_IN);
  
  if (val == HIGH)
  {
    Serial.println("Motion detected");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("...........");
    digitalWrite(LED, LOW);
  }
}
