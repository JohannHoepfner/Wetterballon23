#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

int bmeInit()
{
    if (!bme.begin(0x76))
    {
        // TODO ERROR HANDLING
        return 1;
    }
    return 0;
}

/// Get Temp in Celsius
float bmeTempRead()
{
    return bme.readTemperature();
}

// Get Pressn in hPa
float bmePressRead()
{
    return bme.readPressure() / 100.0F;
}

float bmeHumidRead()
{
    return bme.readHumidity();
}
