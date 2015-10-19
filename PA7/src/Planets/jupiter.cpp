#include "jupiter.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Jupiter::Jupiter()
    :   Planet( ":/texture/jupiter.jpg" )
{
    actualSize = 0.3180f;
    scaledSize = 2.0f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Jupiter::update()
{
    transform.rotate( 1.41f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}