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

void Saturn::initializeGL()
{
    Planet::initializeGL();
}


void Saturn::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
}

void Saturn::update()
{
    if( Planet::SCALED )
        updateScaled();
    else
        updateReal();   
}

void Saturn::teardownGL()
{
    Planet::teardownGL();
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//

void Saturn::updateScaled()
{
    // SATURN
    {
        transform.rotate( 1.0f, 0, 1, 0 );
    }
}

void Saturn::updateReal()
{

}
