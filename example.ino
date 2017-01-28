#include <Arduino.h>
#include "SI7021Library.h"

SI7021Library sensor(12, 14);

void setup()
{
  Serial.begin(9600);
  sensor.init();
}

void loop()
{
  if(sensor.isAvailable() == true)
  {
    
    float temperatureC = sensor.getTemperature(CELSIUS);
    float temperatureF = sensor.getTemperature(FAHRENHEIT);
    float temperatureK = sensor.getTemperature(KELVIN);
    float temperatureR = sensor.getTemperature(RANKINE);
    float humidity = sensor.getHumidity();

    Serial.print("Celcius:");
    Serial.println(temperatureC);
    Serial.print("Fahrenheit:");
    Serial.println(temperatureF);
    Serial.print("Kelvin:");
    Serial.println(temperatureK);
    Serial.print("Rankine:");
    Serial.println(temperatureR);
    
    Serial.print("Humidity:");
    Serial.print(humidity);
    Serial.println("%");

    Serial.println("~~~~~~~~~~~~~~~~~~~~~");
  }

  delay(10000);
}
