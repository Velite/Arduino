#include <dht.h>
#include "U8glib.h"

DHT sensor = DHT();
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

void setup()
{
  sensor.attach(A0);
  delay(1000);
  Serial.begin(9600);
}

void loop()
{
  static uint8_t i = 0;
  sensor.update();
  i++;
  if (i > 122)
  {
    i = 0;
  }

  char temp[128];
  char hum[128];
  switch (sensor.getLastError())
  {
  case DHT_ERROR_OK:
    {
      sprintf(temp, "Temper: %dC", sensor.getTemperatureInt());
      sprintf(hum,  "Humid:  %d%%", sensor.getHumidityInt());

      break;
    }
  }  

  u8g.firstPage();  
  do
  {    
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(0, 10, temp);
    u8g.drawStr(0, 21, hum);    
    u8g.drawFrame(0, 58, 126, 6);
    u8g.drawBox(2, 60, i, 2);
  }
  while(u8g.nextPage());
  
  Serial.println(String(temp) + " " + String(hum));

  delay(1000);
}

