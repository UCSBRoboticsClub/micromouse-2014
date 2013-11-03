#include "drv8833.h"
#include <WProgram.h>
#include <cmath>
#include "Hardware.h"


Motor::Motor(int pin1, int pin2) : pin1(pin1), pin2(pin2)
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    
    // Set PWM frequency to 25kHz
    analogWriteFrequency(pin1, 25000);
    analogWriteFrequency(pin2, 25000);
    pwmWrite(pin1, 0.f);
    pwmWrite(pin2, 0.f);
}


void Motor::write(float value)
{
    if (value < 0.f)
    {
        pwmWrite(pin1, fabs(value));
        digitalWrite(pin2, 0);
    }
    else
    {
        digitalWrite(pin1, 0);
        pwmWrite(pin2, fabs(value));
    }
}


Motor& Motor::operator=(float value)
{
    write(value);
    return *this;
}


void Motor::brake()
{
    digitalWrite(pin1, 1);
    digitalWrite(pin2, 1);
}
