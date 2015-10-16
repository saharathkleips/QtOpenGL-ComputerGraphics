#ifndef MARS_H
#define MARS_H

#include "planet.h"

class Mars     :   public Planet
{
public:
    Mars();

    void update();
};

#endif  //  MARS_H