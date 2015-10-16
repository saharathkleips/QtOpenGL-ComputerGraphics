#ifndef NEPTUNE_H
#define NEPTUNE_H

#include "planet.h"

class Neptune     :   public Planet
{
public:
    Neptune();

    void update();
};

#endif  //  NEPTUNE_H