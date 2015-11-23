#include "time.h"

Time::Time()
{
    dt1 = std::chrono::high_resolution_clock::now();
}

float Time::deltaTime()
{
    dt2 = std::chrono::high_resolution_clock::now();
    float delta = std::chrono::duration_cast< std::chrono::duration<float> >(
        dt2 - dt1 ).count();
    dt1 = std::chrono::high_resolution_clock::now();

    return delta;
}