#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 5
#define BME_MISO 4
#define BME_MOSI 6
#define BME_CS 9

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

int bmeInit()
{
  unsigned status = bme.begin();
  return 0;
}

float bmeHumidRead()
{
  float humid = bme.readHumidity();
  return humid;
}

float bmePressRead()
{
  return bme.readPressure() / 100.0F;
}
