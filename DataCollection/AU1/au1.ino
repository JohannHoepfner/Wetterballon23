#include <SDWriter.h>
#include <RTC-Time.h>

void setup()
{
  SdInit("AU1.csv");
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
  String mesString = String(cTemp,5) + ", " 
                   + String(cHumid,5) + ", "
                   + String(tempC) + ", " 
                   + String(pressHPa) + ", " 
                   + String(humid) + ",";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  int sdErr = SdWrite(saveStr);
  if(sdErr){
    Serial.println("SD Error");
  }
  Serial.println(saveStr);

  updateBeep(pressHPa);
}
