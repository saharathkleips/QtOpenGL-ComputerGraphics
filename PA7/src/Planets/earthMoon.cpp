#include "earthMoon.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

EarthMoon::EarthMoon()
    :   Planet( ":/texture/moonmap.jpg" )
{
    transform.setScale( .50f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void EarthMoon::update()
{
    transform.rotate( 0.27f, 0, 1, 0 );
}