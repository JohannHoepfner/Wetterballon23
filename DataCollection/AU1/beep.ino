int beepPin = 7;

int initBeep()
{
  pinMode(beepPin, OUTPUT);
  return 0;
}

bool armed = false;

float armBelow = 300.0;
float actAbove = 850.0;

int updateBeep(float pressure)
{
  if (armed)
  {
    if (pressure > actAbove)
    {
      digitalWrite(beepPin, HIGH);
      Serial.println("activated");
    }
  }
  else if (pressure < armBelow)
  {
    armed = true;
    Serial.println("armed");
  }
  return 0;
}
