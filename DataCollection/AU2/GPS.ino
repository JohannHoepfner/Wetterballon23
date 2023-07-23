

#include <SoftwareSerial.h>
#include <SD.h>

const int GPS_RX_PIN = 4;   // GPS module RX pin connected to Arduino pin 10
const int GPS_TX_PIN = 3;   // GPS module TX pin connected to Arduino pin 11

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

void GPSinit() {
  gpsSerial.begin(9600);
  gpsSerial.setTimeout(1000);
}

String GPSRead() {
  if(gpsSerial.available()) {
    String nmeaSentence = gpsSerial.readStringUntil('\n');
    return nmeaSentence;
  }
  return "";
}



/* // Define SoftwareSerial Connection   
#define swsTX 3 // Transmit FROM GPS
#define swsRX 4 // Receive TO GP
 
//GPS Baud rate
#define GPSBaud 9600 
 
//Serial Monitor Baud Rate
#define Serial_Monitor_Baud 9600   
 
// Include and set up the SoftwareSerial Library
#include <SoftwareSerial.h> 
SoftwareSerial GPSserial(swsRX, swsTX);  
 
void setup()
{
 //Start Serial Monitor
 Serial.begin(Serial_Monitor_Baud); 
 
 // Start SoftwareSerial  
 GPSserial.begin(GPSBaud);

 SdInit();
}


void loop()
{
  // Write SoftwareSerial data to Serial Monitor
  while (GPSserial.available() > 0){
    Serial.write(GPSserial.read());
  }
}

*/



/*

#define swsTX 3
#define swsRX 4
#define GPSBaud 9600

#include <SoftwareSerial.h> 
SoftwareSerial GPSserial(swsRX, swsTX);  

int initGPS()
{
  GPSserial.begin(GPSBaud);
  return 0;
}
    
String readGPS()
{
  String packet = "";
  
  while (true) {
    if (GPSserial.available()) {
      char readChar = GPSserial.read();
      
      if (readChar == '\n' || readChar == '\r') {
        if (packet.length() > 0) {
          return packet;  // Return the complete NMEA data packet
        }
      } else if (isAscii(readChar)) {
        packet += readChar;
      }
    }
  }
}

*/
