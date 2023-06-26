void setup()
{
  SdInit();
  Serial.begin(9600);
  
  ozonInit();
  bmeInit();
  
  initTime();
}

void loop()
{  
  // Read from Ozon Sensor
  float ozonH, ozonL;
  ozonRead(&ozonH, &ozonL);

  // Read from Temp and Pressure Sensor
  float tempC = bmeTempRead();
  float pressHPa = bmePressRead();

  // Join together measurements
  String mesString 
    = String(ozonH) + ", "
    + String(ozonL) + ", "
    + String(tempC) + ", "
    + String(pressHPa) + ", ";

  // Append Time
  String saveStr = getTime() + ", " + mesString;

  // Log Data
  SdWrite(saveStr);
  Serial.println(saveStr);
  
}
