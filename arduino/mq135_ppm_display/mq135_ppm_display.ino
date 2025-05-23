#include <U8glib.h>
#include <MQ135.h>

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);
MQ135 s1 = MQ135(A0);
MQ135 s2 = MQ135(A1);

float ppm1, ppm2, rz1, rz2;
int modePin = 12;

void displayAirQuality(float ppm1, float ppm2)
{ 
  u8g.setFont(u8g_font_profont15);
  u8g.setPrintPos(5, 10);
  u8g.print("Sensor In:");
  u8g.setPrintPos(5, 25);
  u8g.print(ppm1);
  u8g.print(" ppm");
  u8g.setPrintPos(5, 42);
  u8g.print("Sensor Out:");
  u8g.setPrintPos(5, 57);
  u8g.print(ppm2);
  u8g.print(" ppm");

  Serial.print("Sensor  In: ");
  Serial.print(ppm1);
  Serial.println(" ppm");
  Serial.print("Sensor  Out: ");
  Serial.print(ppm2);
  Serial.println(" ppm");
  Serial.println("\n");
}

void displayRZeroValues(float rz1, float rz2)
{ 
  u8g.setFont(u8g_font_profont15);
  u8g.setPrintPos(5, 10);
  u8g.print("Sensor In:");
  u8g.setPrintPos(5, 25);
  u8g.print(rz1);
  u8g.setPrintPos(5, 42);
  u8g.print("Sensor Out:");
  u8g.setPrintPos(5, 57);
  u8g.print(rz2);

  Serial.print("Sensor  In: ");
  Serial.println(rz1);
  Serial.print("Sensor  Out: ");
  Serial.println(rz2);
  Serial.println("\n");
}

void setup()
{
  pinMode(modePin, INPUT);
  Serial.begin(9600);
}

void loop()
{  
  if (digitalRead(modePin))
  {
    ppm1 = s1.getPPM();
    ppm2 = s2.getPPM();
    u8g.firstPage();
    do
    {
      displayAirQuality(ppm1, ppm2);
    }
    while (u8g.nextPage());
  }
  else
  {
    rz1 = s1.getRZero();
    rz2 = s2.getRZero();
    u8g.firstPage();
    do
    {
      displayRZeroValues(rz1, rz2);
    }
    while (u8g.nextPage());
  }
  delay(1000);
}
