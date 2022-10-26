#include <U8glib.h>
#include <MQ135.h>
#include <DHT.h>

float ppm, conc, t, h;
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);
MQ135 gas = MQ135(A0);
DHT dht(2, DHT11);

void display()
{ 
  u8g.setFont(u8g_font_profont15);
  u8g.setPrintPos(5, 10);
  u8g.print(ppm);
  u8g.print(" ppm");
  u8g.setPrintPos(5, 25);
  u8g.print(conc);
  u8g.setPrintPos(5, 40);
  u8g.print(t);
  u8g.print(" °C");
  u8g.setPrintPos(5, 55);
  u8g.print(h);
  u8g.print(" %");
}

void setup()
{
  
}

void loop()
{
  t = dht.readTemperature();
  h = dht.readHumidity();
  
  ppm = gas.getPPM();
  conc = gas.getRZero();
  
  u8g.firstPage();
  do
  {
    display(); 
  }
  while (u8g.nextPage());
}
