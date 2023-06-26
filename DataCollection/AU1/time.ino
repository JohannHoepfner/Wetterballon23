#include "RTClib.h"

RTC_DS1307 rtc;

String getTime() {
  
  if (!rtc.isrunning()) initialiseClock();
  

  DateTime now = rtc.now();
  String nowtime = "";

  nowtime += now.unixtime();
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
  return 0;
}

bool initialiseClock() {
  delay(50);

  bool begin = rtc.begin();

  if (! begin) {
    return false;
  }
  
  if (! rtc.isrunning()) {

    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    return true;
  }

  delay(50);

  return true;
}
