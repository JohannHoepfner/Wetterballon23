#define sdport 10
#include <SPI.h>
#include <SD.h>


int SdInit(){
  pinMode(sdport, OUTPUT);
  return 0;
}

int SdWrite(String text){
  SD.begin(sdport);
  String fileName = "test.txt";
  File file = SD.open(fileName, FILE_WRITE);
  if (!file) {
    return 1;
  }
  file.println(text); 
  file.flush();
  file.close();
  SD.end();
  return 0;
}
