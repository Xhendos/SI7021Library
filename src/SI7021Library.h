#include <Arduino.h>

#ifndef SI7021LIBRARY_H
#define SI7021LIBRARY_H

#define Address     0x40

enum Temperature
{
  CELSIUS,
  FAHRENHEIT,
  KELVIN,
  RANKINE
};

class SI7021Library
{
    public:
      SI7021Library(int serial_data, int serial_clock);

      void init();
      
      bool isAvailable(); 
      int getRevision();
      void reset();

      float getHumidity();
      float getTemperature(Temperature temperature);
      
    protected:
      
    private:
      int sda;
      int scl;
};

#endif // SI7021LIBRARY_H
