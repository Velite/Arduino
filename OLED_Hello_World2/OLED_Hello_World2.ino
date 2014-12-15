#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup(){
  sensors.begin();
  sensors.getAddress(insideThermometer, 0);
  sensors.setResolution(TEMP_12_BIT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  display.drawPixel(10, 10, WHITE);
}

void loop(){
  sensors.requestTemperatures();
}

