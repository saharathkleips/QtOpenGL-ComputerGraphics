#ifndef EARTH_H
#define EARTH_H

#include "planet.h"
#include "earthMoon.h"

class Earth     :   public Planet
{
public:
    Earth();
    
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    void updateReal();
    void updateScaled();
    EarthMoon *moon;
};

#endif  //  EARTH_H