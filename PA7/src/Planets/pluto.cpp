#include "pluto.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Pluto::Pluto()
    :   Planet( ":/texture/pluto.jpg" )
{

    actualSize = 0.002f;
    scaledSize = 0.4f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Pluto::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}