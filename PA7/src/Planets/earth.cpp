#include "earth.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Earth::Earth()
    :   Planet( ":/texture/earth.jpg" )
{
    transform.setScale( .75f );

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
    if( Planet::SCALED )
        updateScaled();
    else
        updateReal();

    moon->update();

    
}

void Earth::teardownGL()
{
    moon->teardownGL();
    Planet::teardownGL();
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//

void Earth::updateScaled()
{
    // EARTH
    {
        transform.rotate( 1.0f, 0, 1, 0 );
    }

    // MOON
    {
        moon->transform.setScale(0.35f);
        static float translationAngle = 0.0;
        translationAngle += 0.090;
        moon->transform.setTranslation(
            transform.translation().x() + 1.5f * sin(translationAngle),
            transform.translation().y(),
            transform.translation().z() + 1.5f * cos(translationAngle));
    }
}

void Earth::updateReal()
{

}
