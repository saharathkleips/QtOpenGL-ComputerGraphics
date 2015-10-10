#include "planetSun.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

PlanetSun::PlanetSun()
    :   Planet( ":/texture/sun.jpg" )
{
    Planet::transform.setScale( 1 );
}

//
// OVERRIDDEN FUNCTIONS
// 

void PlanetSun::update()
{
    Planet::transform.rotate( 1.0f, 0, 1, 0 );
}