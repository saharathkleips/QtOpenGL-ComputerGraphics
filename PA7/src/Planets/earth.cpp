#include "earth.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Earth::Earth()
    :   Planet( ":/texture/earth.jpg" )
{
    actualSize = 0.09158f;
    scaledSize = 0.5f;
    
    transform.setScale( actualSize );

    moon = new EarthMoon();
}

//
// OVERRIDDEN FUNCTIONS
// 


void Earth::initializeGL()
{
    Planet::initializeGL();
    moon->initializeGL();
}


void Earth::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
    moon->paintGL( camera, projection );
}

void Earth::update()
{
    // rotate earth
    transform.rotate( 10.0f, 0, 1, 0 );


    if( Planet::SCALED )
    {
        transform.setScale( scaledSize );
    }

    else
    {
        transform.setScale( actualSize );
    }

    // translate moon
    static float translationAngle = 0.0;
    translationAngle += 0.070;
    moon->transform.setTranslation(
        transform.translation().x() + 0.85f * sin(translationAngle),
        transform.translation().y(),
        transform.translation().z() + 0.85f * cos(translationAngle)
    );

    moon->update();    
}

void Earth::teardownGL()
{
    moon->teardownGL();
    Planet::teardownGL();
}
