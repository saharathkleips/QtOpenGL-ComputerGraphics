#include "mars.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Mars::Mars()
    :   Planet( ":/texture/mars.jpg" )
{
    actualSize = 0.0107f;
    scaledSize = 0.3f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Mars::update()
{
    transform.rotate( 9.03f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}