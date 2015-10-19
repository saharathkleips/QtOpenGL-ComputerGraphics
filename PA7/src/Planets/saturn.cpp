#include "saturn.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Saturn::Saturn()
    :   Planet( ":/texture/saturn.jpg" )
{
    transform.setScale( 0.166f );
    ring = new Ring( ":/texture/saturnring.jpg" );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Saturn::initializeGL()
{
    Planet::initializeGL();
    ring->initializeGL();
}


void Saturn::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
    ring->paintGL( camera, projection );
}

void Saturn::update()
{
    if( Planet::SCALED )
        updateScaled();
    else
        updateReal();

    ring->update();   
}

void Saturn::teardownGL()
{
    ring->teardownGL();
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
    // RING
    {
        ring->transform.setScale( 0.166f );
        ring->setTranslation( transform.translation() );
    }
}

void Saturn::updateReal()
{

}
