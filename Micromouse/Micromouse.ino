#include <Encoder.h>
#include "RingBuffer.h"

Encoder encoder(2, 3);
RingBuffer<int, 5> encoderCounts;

const int loopPeriodMs = 20;
unsigned int lastMillis = 0;
float wheelCircumference = 0.1f;

float velocity(RingBuffer<int, 5>& x);


void setup()
{
    Serial.begin(115200);
}


void loop()
{
    encoderCounts.push(encoder.read());
    Serial.println(velocity(encoderCounts) * 100.f);
    
    while (millis() - lastMillis < loopPeriodMs);
    lastMillis = millis();
}


float velocity(RingBuffer<int, 5>& x)
{
    // Uses a 4th order backward finite difference method the approximate the derivative of a set of data
    return wheelCircumference * ( 2.08333f * x[0] - 4.f * x[1] + 3.f * x[2] - 1.33333f * x[3] + 0.25f * x[4] ) * loopPeriodMs / 1000.f;
}