#ifndef SATURN_H
#define SATURN_H

#include "planet.h"

class Saturn     :   public Planet
{
public:
    Saturn();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    void updateReal();
    void updateScaled();
};

#endif  //  SATURN_H