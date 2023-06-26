void setup()
{
  Serial.begin(9600);
  ozonInit();
  int err = bmeInit();
  if (err)
  {
    Serial.println("BME280 init error");
  }
  SdInit();
}

void loop()
{
  float ozonH, ozonL;
  ozonRead(&ozonH, &ozonL);

  float tempC = bmeTempRead();
  float pressHPa = bmePressRead();

  String mesString 
    = String(ozonH) + ", "
    + String(ozonL) + ", "
    + String(tempC) + ", "
    + String(pressHPa) + ", ";

  String saveStr = mesString;

  SdWrite(saveStr);
  Serial.println(saveStr);
}
