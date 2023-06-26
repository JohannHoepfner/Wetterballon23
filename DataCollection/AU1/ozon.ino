int ozonInit()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    return 0;
}

int ozonRead(float *varH, float *varL)
{
    int valueA0 = analogRead(A0);
    int valueA1 = analogRead(A1);

    float valueHIGH1 = valueA0 * 5;
    float valueHIGH = valueHIGH1 / 1023;
    float valueLOW1 = valueA1 * 5;
    float valueLOW = valueLOW1 / 1023;

    *varH = valueHIGH;
    *varL = valueLOW;

    return 0;
}
