#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

Adafruit_BME280 bme(BME_CS);

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
