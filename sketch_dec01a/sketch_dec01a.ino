#include <SPI.h>
#include <dht.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//SW SPI
// pin 3 - Serial clock out (SCLK)
// pin 4 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 7 - LCD chip select (CS)
// pin 6 - LCD reset (RST)
//Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 7, 6);

//HW SPI
// CLK - pin 13
// DIN - pin 11
// pin 5 - Data/Command select (D/C)
// pin 4 - CS/CE?
// pin 3 - RST
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 4, 3);
DHT sensor = DHT();
int i = 0;
void setup()
{

  // Инициализация дисплея
  display.begin();

  // Очищаем дисплей
  display.clearDisplay();
  display.display();

  // Устанавливаем контраст
  display.setContrast(50);
  
  //Подключаем датчик
  sensor.attach(A0);
  delay(1000);
}

void loop() 
{
  i++;
  if (i > 83)
  {
    i = 0;
  }
  sensor.update();
  char temp[128];
  char hum[128];
  switch (sensor.getLastError())
  {
    case DHT_ERROR_OK:
    {
      sprintf(temp, "Temperat:  %dC", sensor.getTemperatureInt());
      sprintf(hum,  "Humidity:  %d%%", sensor.getHumidityInt());

      break;
    }
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(temp);
  display.println(hum);
  display.drawFastHLine(0, 47, i, BLACK);
  display.display();
  delay(2000);
}
