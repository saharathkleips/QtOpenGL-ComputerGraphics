#ifndef EARTH_H
#define EARTH_H

#include "planet.h"
#include "earthMoon.h"

class Earth     :   public Planet
{
public:
    Earth();
    
    void update();
private:
    EarthMoon *moon;
};

#endif  //  EARTH_H