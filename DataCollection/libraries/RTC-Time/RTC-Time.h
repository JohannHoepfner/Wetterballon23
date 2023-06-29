#include "RTClib.h"

RTC_DS1307 rtc;

String getTime();
bool initialiseClock();
int initTime();

int TimeZoneSecOffset = 7200;

String getTime() {
  
  if (!rtc.isrunning()) initialiseClock();
  

  DateTime now = rtc.now();

  String nowtime = "";

  nowtime += (now.unixtime()-TimeZoneSecOffset);
  nowtime +=  ", ";

  nowtime += now.year();
  nowtime += '-';
  nowtime += now.month();
  nowtime += '-';
  nowtime += now.day();
  nowtime += ",";
  nowtime += now.hour();
  nowtime += ':';
  nowtime += now.minute();
  nowtime += ':';
  nowtime += now.second();
  nowtime += '.';

  return nowtime;
}

int initTime(){
  if (!initialiseClock()) while (1);
  
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  return 0;
}

bool initialiseClock() {
  delay(50);

  bool begin = rtc.begin();

  if (! begin) {
    return false;
  }
  
  if (! rtc.isrunning()) {
    return true;
  }

  delay(50);

  return true;
}
