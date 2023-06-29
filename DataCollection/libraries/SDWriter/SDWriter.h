#define sdport 10
#include <SPI.h>
#include <SD.h>

String fileName;

int SdInit(String fn)
{
  pinMode(sdport, OUTPUT);
  fileName = fn;
  return 0;
}

int SdWrite(String text)
{
  SD.begin(sdport);
  File file = SD.open(fileName, FILE_WRITE);
  if (!file)
  {
    return 1;
  }
  file.println(text);
  file.flush();
  file.close();
  SD.end();
  return 0;
}
