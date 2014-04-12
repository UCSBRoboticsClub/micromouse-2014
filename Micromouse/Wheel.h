#ifndef WHEEL_H
#define WHEEL_H

#include <Encoder.h>
#include "./LowPass.h"
#include "./Motor.h"


class Wheel
{
public:
    Wheel(int motPin1, int motPin2, int encPin1, int encPin2, float dt, float circumference, int cpr);
    void update();
    void setVelocity(float vel);
    float getVelocity();
    void setPosition(float pos);
    float getPosition();
    
    ControlLoop velocityLoop;
    ControlLoop positionLoop;
    
private:
    Motor motor;
    Encoder encoder;
    int lastCount;
    LowPass velocity;
    bool positionMode;
    float velocitySetpoint;
    float positionSetpoint;
    float dt;
    float count2dist;
};

#endif // WHEEL_H