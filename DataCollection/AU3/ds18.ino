#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int ds18Init()
{
  sensors.begin();
  return 0;
}

float ds18Read()
{
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
