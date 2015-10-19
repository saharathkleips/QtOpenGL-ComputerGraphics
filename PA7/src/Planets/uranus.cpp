#include "uranus.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Uranus::Uranus()
    :   Planet( ":/texture/uranus.jpg" )
{
    actualSize = 0.0145f;
    scaledSize = 0.4f;

    transform.setScale( actualSize );
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
    transform.rotate( -1.72f, 0, 1, 0 );

    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
        ring->transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
        ring->transform.setScale( actualSize );
    }

    ring->transform.setTranslation( transform.translation() );
    ring->update();   
}

void Uranus::teardownGL()
{
    ring->teardownGL();
    Planet::teardownGL();
}
