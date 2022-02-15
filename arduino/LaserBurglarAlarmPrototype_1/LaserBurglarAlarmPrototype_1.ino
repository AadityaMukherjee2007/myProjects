int laser = 4, sensor = 7, alarm = 2;

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
      digitalWrite(alarm, HIGH);
    }
  }
}
