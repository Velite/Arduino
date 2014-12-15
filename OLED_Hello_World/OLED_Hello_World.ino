#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <OzOLED.h>

#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;

void setup(){
  OzOled.init();

  sensors.begin();
  sensors.getAddress(insideThermometer, 0);
  sensors.setResolution(TEMP_12_BIT);
}

void loop(){
  sensors.requestTemperatures();

OzOled.setCursorXY(0, 0);
  OzOled.printString("Temp: ");  
  OzOled.printNumber(sensors.getTempC(insideThermometer), 2);
    OzOled.printString(" C  ");
}
