#ifndef EARTH_H
#define EARTH_H

#include "planet.h"

class Earth     :   public Planet
{
public:
    Earth();

    void update();
};

#endif  //  EARTH_H