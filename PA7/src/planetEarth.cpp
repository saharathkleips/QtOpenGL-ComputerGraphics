#include "planetEarth.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

PlanetEarth::PlanetEarth()
    :   Planet( ":/texture/earth.jpg" )
{
    Planet::transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void PlanetEarth::update()
{
    Planet::transform.rotate( 1.0f, 0, 1, 0 );
}