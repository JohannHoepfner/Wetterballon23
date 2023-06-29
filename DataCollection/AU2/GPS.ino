 // Define SoftwareSerial Connection   
#define swsTX 3 // Transmit FROM GPS
#define swsRX 4 // Receive TO GPS

#include <SoftwareSerial.h>

SoftwareSerial GPSserial(swsRX, swsTX); 

int GPSinit(){
  GPSserial.begin(9600);
  return 0;
}

String GPSRead(int numMessages,int maxmillis){
  int startmillis = millis();  
  
  String text;
  
  int countGGA = 0;
  int countGLL = 0;
  
  while(true){
    
    if (GPSserial.available()) {
      
      String sentence = GPSserial.readStringUntil('\n');
      
      if (sentence.startsWith("$GNGGA"))  countGGA++;
      if (sentence.startsWith("$GNGLL"))  countGLL++;
      
      text+=sentence+'\n';
    }
    
    if((countGGA>=numMessages) && (countGLL>=numMessages)) break;

    if(millis()>maxmillis+startmillis) break;

    
  }
  return text;
}



/* // Define SoftwareSerial Connection   
#define swsTX 3 // Transmit FROM GPS
#define swsRX 4 // Receive TO GPS
 
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
