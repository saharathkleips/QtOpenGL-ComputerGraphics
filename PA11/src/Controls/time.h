#ifndef TIME_H
#define TIME_H

#include <chrono>

class Time
{
public:
    Time();
    float deltaTime();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> dt1, dt2;
};

#endif  //  TIME_H