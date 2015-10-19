#include "earth.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Earth::Earth()
    :   Planet( ":/texture/earth.jpg" )
{
    transform.setScale( 0.09158f );

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
        transform.setScale( 0.6f );
        moon->transform.setScale( 0.2f );
    }

    else
    {
        transform.setScale( 0.09158f );
        moon->transform.setScale(0.011f);
    }

    // Moon
    {
        static float translationAngle = 0.0;
        translationAngle += 0.070;
        moon->transform.setTranslation(
            transform.translation().x() + 1.5f * sin(translationAngle),
            transform.translation().y(),
            transform.translation().z() + 1.5f * cos(translationAngle)
        );
    }
    moon->update();

    
}

void Earth::teardownGL()
{
    moon->teardownGL();
    Planet::teardownGL();
}
