#include <SPI.h>
#include <MFRC522.h>

#define ss_pin 10
#define rst_pin 9
MFRC522 mfrc522(ss_pin, rst_pin);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void loop()
{
  if (! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  else if (! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print("UID Tag: ");
  String content = "";
  byte letter;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();

  if (content.substring(1) == "E9 2E BF A2")
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
  }
  else
  {
    Serial.println(" Access denied");
    delay(3000);
  }
}
