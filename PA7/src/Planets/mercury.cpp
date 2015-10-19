#include "mercury.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Mercury::Mercury()
    :   Planet( ":/texture/mercury.jpg" )
{
    transform.setScale( .0055f );
}

//
// OVERRIDDEN FUNCTIONS
// 
void Mercury::update()
{
    transform.rotate( 5.865f, 0, 1, 0 );
}