#include <SDWriter.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  SdInit("AU2.gps");
  
  GPSinit();
}

void loop() {
  auto txt = GPSRead();
  if(txt!=""){
    Serial.println(txt);
    int sdErr = SdWrite(txt);
    if(sdErr){
      Serial.println("SD Error");
    }
  }
}
