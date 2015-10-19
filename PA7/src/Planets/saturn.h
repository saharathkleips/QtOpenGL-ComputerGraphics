#ifndef SATURN_H
#define SATURN_H

#include "planet.h"
#include "../ring.h"

class Saturn     :   public Planet
{
public:
    Saturn();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    Ring *ring;
};

#endif  //  SATURN_H