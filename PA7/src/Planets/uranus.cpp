#include "uranus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Uranus::Uranus()
    :   Planet( ":/texture/uranus.jpg" )
{
    transform.setScale( .75f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Uranus::update()
{
    transform.rotate( 1.0f, 0, 1, 0 );
}