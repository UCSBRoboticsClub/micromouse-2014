#ifndef DRV8833_H
#define DRV8833_H


class Motor
{
public:
    Motor(int speedPin, int phasePin);
    void write(float value);
    Motor& operator=(float value);
    void brake();
    
private:
    const int pin1;
    const int pin2;
};

#endif // DRV8833_H