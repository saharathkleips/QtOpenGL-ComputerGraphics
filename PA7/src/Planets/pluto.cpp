#include "pluto.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Pluto::Pluto()
    :   Planet( ":/texture/pluto.jpg" )
{
    transform.setScale( .002f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Pluto::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}