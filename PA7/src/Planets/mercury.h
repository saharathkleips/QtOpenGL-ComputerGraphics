#ifndef MERCURY_H
#define MERCURY_H

#include "planet.h"

class Mercury     :   public Planet
{
public:
    Mercury();

    void update();
};

#endif  //  MERCURY_H