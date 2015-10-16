#ifndef JUPITER_H
#define JUPITER_H

#include "planet.h"

class Jupiter     :   public Planet
{
public:
    Jupiter();

    void update();
};

#endif  //  JUPITER_H