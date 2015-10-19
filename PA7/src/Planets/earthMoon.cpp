#include "earthMoon.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

EarthMoon::EarthMoon()
    :   Planet( ":/texture/moonmap.jpg" )
{
    actualSize = 0.011f;
    scaledSize = 0.200f;
    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void EarthMoon::update()
{
    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }
    else
    {
        transform.setScale( actualSize );
    }

    transform.rotate( 0.27f, 0, 1, 0 );
}