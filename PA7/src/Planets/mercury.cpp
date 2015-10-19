#include "mercury.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Mercury::Mercury()
    :   Planet( ":/texture/mercury.jpg" )
{
    actualSize = 0.0055f;
    scaledSize = 0.2f;

    transform.setScale( actualSize );
}

//
// OVERRIDDEN FUNCTIONS
// 
void Mercury::update()
{
    transform.rotate( 5.865f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }
}