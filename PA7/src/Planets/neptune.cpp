#include "neptune.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Neptune::Neptune()
    :   Planet( ":/texture/neptune.jpg" )
{
    actualSize = 0.0172f;
    scaledSize = 2.0f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Neptune::update()
{
    transform.rotate( 1.72f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}