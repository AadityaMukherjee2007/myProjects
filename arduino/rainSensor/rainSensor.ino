const int capteur_D = 4;
const int capteur_A = A0;
int alarm = 11;

int val_analogique;

void setup()
{
  pinMode(capteur_D, INPUT);
  pinMode(capteur_A, INPUT);
  pinMode(alarm, OUTPUT);
  digitalWrite(alarm, LOW);
  Serial.begin(9600);
}

void loop()
{
if(digitalRead(capteur_D) == LOW) 
  {
    Serial.println("Digital value : wet"); 
    digitalWrite(alarm, HIGH);
    delay(60000); 
  }
else
  {
    Serial.println("Digital value : dry");
    digitalWrite(alarm, LOW);
    delay(10); 
  }
val_analogique=analogRead(capteur_A); 
 Serial.print("Analog value : ");
 Serial.println(val_analogique); 
 Serial.println("");
  delay(1000);
}
