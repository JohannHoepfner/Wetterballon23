
int initTemp()
{
  return 0;
}
float readTemp()
{
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  return voltage;
}

int Htime; // variable for storing high time
int Ltime; // variable for storing low time
int initHumid()
{
  pinMode(2, INPUT);
  return 0;
}
float readHumid()
{
  int numpulse = 1000;
  float freq = 0;
  for (int i = 0; i < numpulse; i++)
  {
    Htime = pulseIn(2, HIGH); // measure the high time
    Ltime = pulseIn(2, LOW);  // measure the low time

    float Ttime = Htime + Ltime;       // calculate the total time of a cycle
    float frequency = 1000000 / Ttime; // calculate the frequency in Hz

    freq = freq + frequency / float(numpulse);
  }
  return freq;
}
