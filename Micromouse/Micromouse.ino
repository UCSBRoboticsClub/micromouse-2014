#include "./Wheel.h"


unsigned int loopFreq = 1000; // Hz
unsigned int loopPeriodUs = 1000000 / loopFreq;
const float dt = loopPeriodUs / 1000000.f;
unsigned int lastMicros = 0;

// 3 and 4 are motor pins, 0 and 1 are encoder pins
// Change these to fit actual circuit
Wheel wheel(3, 4, 0, 1, dt, 0.1f, 12);


void setup()
{
    Serial.begin(115200);
}


void loop()
{
    wheel.update()
    
    Serial.println(wheel.getVelocity() * 100.f);
    
    // Limit loop speed to a consistent value to make timing and integration simpler
    while (micros() - lastMicros < loopPeriodUs);
    lastMicros = micros();
}
