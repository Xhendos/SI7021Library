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

###isAvailable() [bool]

Sends a command and will read the response from the SLAVE. <br />
If the SLAVE returns the correct address the method returns true. <br />
In any other cases the method returns false.

```C++
bool SI7021Library::isAvailable()
```

###getRevision() [int]
Sends a command and will read the response from the SLAVE. <br />
Possible returns from the SLAVE are <br />

| Revision hexa    | Revision text         | 
| -------------    |:---------------------:| 
| 0xFF (255)       | Firmware version 1.0  |
| 0x20 (32)        | Firmware version 2.0  |

```C++
int SI7021Library::getRevision()
```

###getTemperature(Temperature temperature) [float]
Sends a command and will read the response from the SLAVE. <br />
The programmer can choose what digit should be returned
Values for the parameter Temperature:
| Parameter value  | Description | 
| -------------    |:------------------:| 
| CELSIUS          | Returns temperature in digit celsius     |
| FAHRENHEIT       | Returns temperature in digit fahrenheit  |
| KELVIN           | Returns temperature in digit kelvin      |
| RANKINE          | Returns temperature in digit rankine     |

