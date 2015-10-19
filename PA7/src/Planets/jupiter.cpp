#include "jupiter.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Jupiter::Jupiter()
    :   Planet( ":/texture/jupiter.jpg" )
{
    transform.setScale( .5180f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Jupiter::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}