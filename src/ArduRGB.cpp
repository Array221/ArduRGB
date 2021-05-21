#include "ArduRGB.h"

ArduRGB::ArduRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, bool isCommonAnode=false)
{
    cAnode = isCommonAnode;
    redP = redPin;
    greenP = greenPin;
    blueP = bluePin;
    
    pinMode(redP, OUTPUT);
    pinMode(greenP, OUTPUT);
    pinMode(blueP, OUTPUT);
    
    turnOff();
}
ArduRGB::~ArduRGB()
{
    turnOff();
}
void ArduRGB::setColor(uint8_t red, uint8_t green, uint8_t blue)
{
    colorRed = red;
    colorGreen = green;
    colorBlue = blue;
    
    if(cAnode)
    {
        red = 255 - colorRed;
        green = 255 - colorGreen;
        blue = 255 - colorBlue;
    }
    
    analogWrite(redP, red);
    analogWrite(greenP, green);
    analogWrite(blueP, blue);
}
void ArduRGB::setColor(unsigned long hex)
{
    setColor((hex & 0xff0000) >> 16, (hex & 0x00ff00) >> 8, hex & 0x0000ff);
}
uint8_t ArduRGB::getR()
{
    return colorRed;
}
uint8_t ArduRGB::getG()
{
    return colorGreen;
}
uint8_t ArduRGB::getB()
{
    return colorBlue;
}
void ArduRGB::rainbow(unsigned int colorsDelay=10)
{
    for (int i=0;i<256;i++)
    {
        setColor(255-i, i, 0);
        delay(colorsDelay);
    }
    for (int i=0;i<256;i++)
    {
        setColor(0, 255-i, i);
        delay(colorsDelay);
    }
    for (int i=0;i<256;i++)
    {
        setColor(i, 0, 255-i);
        delay(colorsDelay);
    }
}
void ArduRGB::turnOff()
{
    setColor(0, 0, 0);
}
