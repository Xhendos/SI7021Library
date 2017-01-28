#include "SI7021Library.h"
#include <Arduino.h>
#include <Wire.h>


SI7021Library::SI7021Library(int serial_data, int serial_clock)
{
  sda = serial_data;
  scl = serial_clock;
}

void SI7021Library::init()
{
  Wire.begin(sda, scl);
  Serial.begin(9600);  
}

bool SI7021Library::isAvailable()
{
  Wire.beginTransmission(Address);
  Wire.write(0xFC);
  Wire.write(0xC9);
  Wire.endTransmission(Address);

  Wire.requestFrom(Address, 1);
  uint8_t response = Wire.read();

  if(response == 21)
  {
    return true;
  }

  return false;
  
}

int SI7021Library::getRevision()
{
  Wire.beginTransmission(Address);
  Wire.write(0x84);
  Wire.write(0xB8);
  Wire.endTransmission();

  Wire.requestFrom(Address, 1);
  int response = Wire.read();

  return response;
}

float SI7021Library::getHumidity()
{
  Wire.beginTransmission(Address);
  Wire.write(0xE5);
  Wire.endTransmission();
  
  delay(300);

  Wire.requestFrom(Address, 2);

  float responseA;
  float responseB;

  if(Wire.available() == 2)
  {
    responseA = Wire.read();
    responseB = Wire.read();
  }
  
  float convertedData = ((responseA * 255.0) + responseB);
  float humidity = ((125 * convertedData / 65536) -6);
  
  return humidity;
}

float SI7021Library::getTemperature(Temperature temperature)
{
  Wire.beginTransmission(Address);
  Wire.write(0xE3);
  Wire.endTransmission();
  delay(300);

  Wire.requestFrom(Address, 2);

  float responseA;
  float responseB;

  if(Wire.available() == 2)
  {
    responseA = Wire.read();
    responseB = Wire.read();    
  }

  float convertedData = ((responseA * 255.0) + responseB);

  float temp;

  switch(temperature)
  {
    case CELSIUS:
      temp = ((175.52 * convertedData / 65536.0) - 46.85);
      break;
    case FAHRENHEIT:
      temp = ((((175.52 * convertedData / 66536.0) - 46.85) * 1.8 ) + 32.0);
      break;
    case KELVIN:
      temp = ((175.52 * convertedData / 66536.0) + 224.15);
      break;
    case RANKINE:
      temp = (((175.52 * convertedData / 66536.0) + 224.15) * 9.0 / 5.0 );
      
  }

  return temp;
}

void SI7021Library::reset()
{
  Wire.beginTransmission(Address);
  Wire.write(0xFE);
  Wire.endTransmission();
}
