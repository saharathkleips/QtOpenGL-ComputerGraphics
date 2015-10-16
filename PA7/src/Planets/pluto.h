#ifndef PLUTO_H
#define PLUTO_H

#include "planet.h"

class Pluto     :   public Planet
{
public:
    Pluto();

    void update();
};

#endif  //  PLUTO_H