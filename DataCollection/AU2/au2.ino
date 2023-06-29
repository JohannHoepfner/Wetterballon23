#include <SDWriter.h>
#include <RTC-Time.h>


void setup() {
  Serial.begin(9600);
  GPSinit();
}

void loop() {
  Serial.println(GPSRead(30,2000));
  delay(1000);
}
