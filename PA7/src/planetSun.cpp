#include "planetSun.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

PlanetSun::PlanetSun()
    :   Planet( ":/texture/sun.jpg" )
{
    transform.setScale( 1.0f );
    earth.transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void PlanetSun::initializeGL()
{
    Planet::initializeGL();
    earth.initializeGL();
}

void PlanetSun::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
    earth.paintGL( camera, projection );
}

void PlanetSun::update()
{
    static float translationAngle = 0.0;
    translationAngle += .03;
    earth.transform.setTranslation( 
        transform.translation().x() + 4.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 2.0f * cos( translationAngle ) );

    transform.rotate( 1.0f, 0, 1, 0 );
    
    earth.update();
}

void PlanetSun::teardownGL()
{
    Planet::teardownGL();
    earth.teardownGL();
}