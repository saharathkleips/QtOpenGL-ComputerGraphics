#include "saturn.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Saturn::Saturn()
    :   Planet( ":/texture/saturn.jpg" )
{
    actualSize = 0.166f;
    scaledSize = 0.8f;

    transform.setScale( actualSize );
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
    transform.rotate( 1.44f, 0, 1, 0 );

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

void Saturn::teardownGL()
{
    ring->teardownGL();
    Planet::teardownGL();
}
