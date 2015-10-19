#include "uranus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Uranus::Uranus()
    :   Planet( ":/texture/uranus.jpg" )
{
    transform.setScale( 0.0145f );
    ring = new Ring( ":/texture/uranusring.jpg" );
}

//
// OVERRIDDEN FUNCTIONS
// 

void Uranus::initializeGL()
{
    Planet::initializeGL();
    ring->initializeGL();
}


void Uranus::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
    ring->paintGL( camera, projection );
}

void Uranus::update()
{
    if( Planet::SCALED )
        updateScaled();
    else
        updateReal();

    ring->update();   
}

void Uranus::teardownGL()
{
    ring->teardownGL();
    Planet::teardownGL();
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//

void Uranus::updateScaled()
{
    // URANUS
    {
        transform.rotate( 1.0f, 0, 1, 0 );
    }
    // RING
    {
        ring->transform.setScale( 0.0145f );
        ring->transform.setTranslation( transform.translation() );
    }
}

void Uranus::updateReal()
{

}
