# SI7021Library
C++ library for the SI7021 sensor



##API

| Function name    | Added since   | 
| -------------    |:-------------:| 
| init()           | Version 0.1   |
| isAvailable()    | Version 0.1   |
| getRevision()    | Version 0.1   |
| reset()          | Version 0.1   |
| getHumidity()    | Version 0.1   |
| getTemperature() | Version 0.1   |


###init() [void]

Initialize the Wire library with the correct SerialClock and SerialData pins.  
This method should ALWAYS been called before using any other methods of the API. <br />
The method does not return anything.

```C++
void SI7021Library::init()
```



