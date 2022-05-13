//ce = 11, csn = 9
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(11, 9);
const byte address[6] = "000001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
