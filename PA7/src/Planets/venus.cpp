#include "venus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Venus::Venus()
    :   Planet( ":/texture/venus.jpg" )
{
    actualSize = 0.0815f;
    scaledSize = 0.4f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Venus::update()
{
    transform.rotate( -2.243f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}