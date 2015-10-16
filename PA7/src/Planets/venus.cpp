#include "venus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Venus::Venus()
    :   Planet( ":/texture/venus.jpg" )
{
    transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Venus::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}