#include <SDWriter.h>
#include <RTC-Time.h>

void setup()
{
  SdInit("AU1");
  Serial.begin(9600);
  
  bmeInit();
  initTemp();
  initHumid(); 
  
  initTime();

  initBeep();
}

void loop()
{
  // Read from Temp and Pressure Sensor
  float tempC = bmeTempRead();
  float pressHPa = bmePressRead();
  float humid = bmeHumidRead();

  float cTemp = readTemp();
  float cHumid = readHumid();

  // Join together measurements
  String mesString 
    = String(cTemp) + ", "
    + String(cHumid) + ", "
    + String(tempC) + ", "
    + String(pressHPa) + ", "
    + String(humid) + ",";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  SdWrite(saveStr);
  Serial.println(saveStr);
  
  updateBeep(pressHPa);
}
