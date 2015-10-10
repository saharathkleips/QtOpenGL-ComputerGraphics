#ifndef PLANET_EARTH_H
#define PLANET_EARTH_H

#include "planet.h"

class PlanetEarth     :   public Planet
{
public:
    PlanetEarth();

    void update();
};

#endif  //  PLANET_EARTH_H