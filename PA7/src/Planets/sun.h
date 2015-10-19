#ifndef SUN_H
#define SUN_H

#include <QMatrix4x4>
#include <QMap>
#include <QString>

#include "planet.h"
#include "mercury.h"
#include "venus.h"
#include "earth.h"
#include "mars.h"
#include "jupiter.h"
#include "saturn.h"
#include "uranus.h"
#include "neptune.h"
#include "pluto.h"

class Sun     :   public Planet
{
public:
    Sun();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

private:
    void updateScaled();
    void updateReal();
    QMap<QString, Planet*> planets;
};

#endif  //  SUN_H