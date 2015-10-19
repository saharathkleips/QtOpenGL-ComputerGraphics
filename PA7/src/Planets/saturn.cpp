#include "saturn.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Saturn::Saturn()
    :   Planet( ":/texture/saturn.jpg" )
{
    transform.setScale( 0.166f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Saturn::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}