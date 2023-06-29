#include <SDWriter.h>
#include <RTC-Time.h>
#include <Auswerteschaltung.h>

void setup()
{
  SdInit();
  Serial.begin(9600);

  initTemp();
  initHumid(); 
  
  initTime();
}

void loop()
{
  float cTemp = readTemp();
  float cHumid = readHumid();

  // Join together measurements
  String mesString = String(cTemp) + ", " + String(cHumid) + ", ";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  SdWrite(saveStr);
  Serial.println(saveStr);
}
