#ifndef PLANET_SUN_H
#define PLANET_SUN_H

#include "planet.h"

class PlanetSun     :   public Planet
{
public:
    PlanetSun();

    void update();
};

#endif  //  PLANET_SUN_H