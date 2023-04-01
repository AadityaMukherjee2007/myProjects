#include <IRremote.h>

IRrecv IrReciever(13);

void setup()
{
  IrReciever.begin(13);
  Serial.begin(9600);
}

void loop()
{
  delay(1000);
  if (IrReciever.decode())
  {
    IrReciever.resume();
    Serial.println(IrReciever.decodedIRData.command);
  }
}
