#ifndef EARTH_MOON_H
#define EARTH_MOON_H

#include "planet.h"

class EarthMoon     :   public Planet
{
public:
    EarthMoon();
    
    void update();
};

#endif  //  EARTH_MOON_H