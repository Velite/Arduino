#include <SPI.h>
#include <Mirf.h>
#include <MirfHardwareSpiDriver.h>
#include <MirfSpiDriver.h>
#include <nRF24L01.h>

void setup()
{
  /*Mirf.csnPin = 9;
  Mirf.cePin = 7;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"send1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.channel = 100;
  Mirf.config();
  
  byte rf_setup = 0;
  Mirf.readRegister( RF_SETUP, &rf_setup, sizeof(rf_setup) );*/
  Serial.begin(9600);
}

void loop()
{
/*  Mirf.setTADDR((byte *)"serv1");
  Mirf.send((byte*)analogRead(0));
  while(Mirf.isSending())
  {
  }*/
  unsigned int ll = analogRead(1);
  String result = "Light level: ";
  result += ll;
  Serial.println(result);
  delay(1000);
}

