#ifndef ArduRGB

#include <Arduino.h>

class ArduRGB
{
    public:
        // Constructor & Destructor
        ArduRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, bool isCommonAnode=false);
        ~ArduRGB();
        // Setters
        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setColor(unsigned long hex);
        // Getters
        uint8_t getR();
        uint8_t getG();
        uint8_t getB();
        // Other
        void rainbow(unsigned int delay=10);
        void turnOff();
    private:
        bool cAnode;
        // Pins
        uint8_t redP;
        uint8_t greenP;
        uint8_t blueP;
        // Colors
        uint8_t colorRed;
        uint8_t colorGreen;
        uint8_t colorBlue;
};

#define ArduRGB
#endif
