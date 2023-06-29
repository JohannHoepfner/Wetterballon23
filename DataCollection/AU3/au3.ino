#include <SDWriter.h>
#include <RTC-Time.h>

void setup()
{
  
  digitalWrite(3, LOW);
  
  Serial.begin(9600);
  while(!Serial);
  
  SdInit();

  ds18Init();
  bmeInit();

  initTime();

  // 

  
  
}

void loop()
{
  
  float tempC = ds18Read();
  float humid = bmeHumidRead();
  
  // Join together measurements
  String mesString
    = String(tempC) + ", "
    + String(humid) + ",";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  SdWrite(saveStr);
  Serial.println(saveStr);
  
  
}
