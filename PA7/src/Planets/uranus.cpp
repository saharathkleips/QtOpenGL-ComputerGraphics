#include "uranus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Uranus::Uranus()
    :   Planet( ":/texture/uranus.jpg" )
{
    transform.setScale( .0145f );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Uranus::update()
{
    transform.rotate( -1.72f, 0, 1, 0 );
}