int laser = 4, sensor = 7, alarm = 11;

void beep()
{
  digitalWrite(alarm, HIGH);
  delay(150);
  digitalWrite(alarm, LOW);
  delay(150);
}

void setup() {
  pinMode(sensor, INPUT);
  pinMode(laser, OUTPUT);
  pinMode(alarm, OUTPUT);
  digitalWrite(alarm, LOW);
  digitalWrite(laser, HIGH);
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  int sense = digitalRead(sensor);
  if (sense == LOW)
  {
    Serial.println(".......");
    digitalWrite(13, LOW);
    delay(250);
  }
  else
  {
    Serial.println("Burglar Detected!");
    digitalWrite(13, HIGH);
    for(;;)
    {
      beep();
    }
  }
}
