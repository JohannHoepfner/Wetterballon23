#include <SDWriter.h>
#include <RTC-Time.h>


void setup()
{

  digitalWrite(3, LOW);

  Serial.begin(9600);
  while (!Serial);

  SdInit("AU3.csv");

  ds18Init();
  bmeInit();

  initTime();

  //
}

void loop()
{

  float tempC = ds18Read();
  float humid = bmeHumidRead();
  float pressure = bmePressRead();

  // Join together measurements
  String mesString = String(tempC) + ", " + String(humid) + "," + String(pressure) + ",";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  int sdErr = SdWrite(saveStr);
  if(sdErr){
    Serial.println("SD Error");
  }
  
  Serial.println(saveStr);
}
