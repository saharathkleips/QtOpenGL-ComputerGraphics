#include "venus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Venus::Venus()
    :   Planet( ":/texture/venus.jpg" )
{
    transform.setScale( .0815f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Venus::update()
{
    transform.rotate( -2.243f, 0, 1, 0 );
}