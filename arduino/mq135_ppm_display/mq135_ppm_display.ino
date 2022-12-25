#include <U8glib.h>
#include <MQ135.h>

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);
MQ135 s1 = MQ135(A0);
MQ135 s2 = MQ135(A1);

void display(float ppm1, float ppm2)
{ 
  u8g.setFont(u8g_font_profont15);
  u8g.setPrintPos(5, 10);
  u8g.print(ppm1);
  u8g.print(" ppm");
  u8g.setPrintPos(5, 30);
  u8g.print(ppm2);
  u8g.print(" ppm");
}


void setup()
{
  
}

void loop()
{
  float ppm1 = s1.getPPM();
  float ppm2 = s2.getPPM();
  u8g.firstPage();
  do
  {
    display(ppm1, ppm2);
  }
  while (u8g.nextPage());
}
