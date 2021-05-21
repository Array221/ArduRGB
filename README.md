# ArduRGB
Library that handles non-programmable RGB diodes in Arduino. Use with PlatformIO.

## Usage
Create object for diode.
### Common Cathode
```cpp
ArduRGB led(9, 10, 11);
```
Where ```9```, ```10``` and ```11``` are red, green and blue pin of diode.
### Common Anode
```cpp
ArduRGB led(9, 10, 11, true);
```
Where ```9```, ```10``` and ```11``` are red, green and blue pin of diode, and ```true``` argument enables common anode mode.
#### Diode pins should have PWM function!

## Methods
 - ```setColor(red, green, blue)``` - Applies color in RGB format to diode
 - ```setColor(hex)``` - Applies color in hex format to diode
 - ```getR()``` - Returns current RGB red value of diode.
 - ```getG()``` - Returns current RGB green value of diode.
 - ```getB()``` - Returns current RGB blue value of diode.
 - ```rainbow(colorsDelay=10)``` - Displays all rainbow colors on diode with given delays between them(default delay is 10ms).
 - ```turnOff()``` - Turns off diode.

## Exaple programs
### All colors in RGB format
```cpp
#include <Arduino.h>
#include "ArduRGB.h"

ArduRGB led(9, 10, 11);

void setup()
{
    
}

void loop()
{
    led.setColor(255, 0, 0);
    delay(100);
    led.setColor(0, 255, 0);
    delay(100);
    led.setColor(0, 0, 255);
    delay(100);
}
```
### All colors in hex format
```cpp
#include <Arduino.h>
#include "ArduRGB.h"

ArduRGB led(9, 10, 11);

void setup()
{
    
}

void loop()
{
    led.setColor(0xff0000);
    delay(100);
    led.setColor(0x00ff00);
    delay(100);
    led.setColor(0x0000ff);
    delay(100);
}
```
### Endless rainbow
```cpp
#include <Arduino.h>
#include "ArduRGB.h"

ArduRGB led(9, 10, 11);

void setup()
{
    
}

void loop()
{
    led.rainbow();
}
```