#include <Encoder.h>
#include "./Wheel.h"

int motorRF = 23;//right forward motor pin
int motorRR = 22;//right reverse
int motorLR = 21;//left forward
int motorLF =20;//left reverse

int encoderR1 = 19;
int encoderR2 = 18;//both right encoder pins
int encoderL1 = 11;
int encoderL2 = 10;



unsigned int loopFreq = 100; // Hz
unsigned int loopPeriodUs = 1000000 / loopFreq;
const float dt = loopPeriodUs / 1000000.f;
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
