#include <Encoder.h>
#include "./Wheel.h"

const int motorRF = 23; // right forward motor pin
const int motorRR = 22; // right reverse
const int motorLR = 21; // left forward
const int motorLF = 20; // left reverse
const int encoderR1 = 19;
const int encoderR2 = 18; // both right encoder pins
const int encoderL1 = 11;
const int encoderL2 = 10;

const unsigned int loopFreq = 100; // Hz
const unsigned int loopPeriodUs = 1000000 / loopFreq;
const float dt = 1.f / loopFreq;
unsigned int lastMicros = 0;

// 3 and 4 are motor pins, 0 and 1 are encoder pins
// Change these to fit actual circuit
Wheel leftwheel(motorLR, motorLF, encoderL1, encoderL2, dt, 0.1f, 1200);
Wheel rightwheel(motorRR, motorRF, encoderR1, encoderR2, dt, 0.1f, 1200);

void setup()
{
    Serial.begin(115200);
    leftwheel.velocityLoop.setTuning(0.1f, 0.f, 0.1f);
    leftwheel.setVelocity(100.f);
    rightwheel.velocityLoop.setTuning(0.1f, 0.f, 0.1f);
    rightwheel.setVelocity(100.f);
}


void loop()
{
    leftwheel.update();
    rightwheel.update();
    leftwheel.setVelocity(1);
    rightwheel.setVelocity(1);
    
    Serial.println(leftwheel.getVelocity() * 100.f);
    
    // Limit loop speed to a consistent value to make timing and integration simpler
    while (micros() - lastMicros < loopPeriodUs);
    lastMicros = micros();
}
