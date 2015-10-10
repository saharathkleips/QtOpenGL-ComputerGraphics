#ifndef PLANET_SUN_H
#define PLANET_SUN_H

#include <QMatrix4x4>

#include "planet.h"
#include "planetEarth.h"
#include "camera3d.h"

class PlanetSun     :   public Planet
{
public:
    PlanetSun();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    PlanetEarth earth;
};

#endif  //  PLANET_SUN_H