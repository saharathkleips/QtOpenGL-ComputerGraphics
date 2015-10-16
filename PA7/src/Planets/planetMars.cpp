#include "planetMars.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

PlanetMars::PlanetMars()
    :   Planet( ":/texture/mars.jpg" )
{
    Planet::transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void PlanetMars::update()
{
    Planet::transform.rotate( 1.0f, 0, 1, 0 );
}