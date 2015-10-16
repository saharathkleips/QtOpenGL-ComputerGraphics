#ifndef VENUS_H
#define VENUS_H

#include "planet.h"

class Venus     :   public Planet
{
public:
    Venus();

    void update();
};

#endif  //  VENUS_H