#include "sun.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

Sun::Sun()
    :   Planet( ":/texture/sun.jpg" )
{
    transform.setScale( 1.0f );
    
    planets["Mercury"] = new Mercury();
    planets["Venus"] = new Venus();
    planets["Earth"] = new Earth();
    planets["Mars"] = new Mars();
    planets["Jupiter"] = new Jupiter();
    planets["Saturn"] = new Saturn();
    planets["Uranus"] =  new Uranus();
    planets["Neptune"] = new Neptune();
    planets["Pluto"] = new Pluto();
}

//
// OVERRIDDEN FUNCTIONS
// 

void Sun::initializeGL()
{
    Planet::initializeGL();
    
    for( QMap<QString, Planet*>::iterator iter = planets.begin(); 
        iter != planets.end(); iter++ )
    {
        (*iter)->initializeGL();
    }
}

void Sun::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    Planet::paintGL( camera, projection );
    
    // PAINT ALL PLANETS
    for( QMap<QString, Planet*>::iterator iter = planets.begin(); 
        iter != planets.end(); iter++ )
    {
        (*iter)->paintGL( camera, projection );
    }
}

void Sun::update()
{
    if( Planet::SCALED )
        updateScaled();
    else
        updateReal();

    // UPDATE ALL PLANETS
    for( QMap<QString, Planet*>::iterator iter = planets.begin(); 
        iter != planets.end(); iter++ )
    {
        (*iter)->update();
    }
}

void Sun::teardownGL()
{
    // DEALLOCATE ALL PLANETS
    for( QMap<QString, Planet*>::iterator iter = planets.begin(); 
        iter != planets.end(); iter++ )
    {
        (*iter)->teardownGL();
    }

    Planet::teardownGL();
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//


void Sun::updateScaled()
{
    // SUN
    {
        transform.rotate( 0.27f, 0, 1, 0 );
    }

    // MERCURY
    {
        static float translationAngle = 2.0;
        translationAngle += .0040;
        planets["Mercury"]->transform.setTranslation( 
        transform.translation().x() + 3.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 3.0f * cos( translationAngle ) );
    }

    // VENUS
    {
        static float translationAngle = 23.0;
        translationAngle += .0070;
        planets["Venus"]->transform.setTranslation( 
        transform.translation().x() + 6.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 6.0f * cos( translationAngle ) );
    }

    // EARTH
    {
        static float translationAngle = 10.0;
        translationAngle += .0090;
        planets["Earth"]->transform.setTranslation( 
        transform.translation().x() + 9.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 9.0f * cos( translationAngle ) );
    }

    // MARS
    {
        static float translationAngle = 8.0;
        translationAngle += .00018;
        planets["Mars"]->transform.setTranslation( 
        transform.translation().x() + 15.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 15.0f * cos( translationAngle ) );
    }

    // JUPITER
    {
        static float translationAngle = 20.0;
        translationAngle += .00050;
        planets["Jupiter"]->transform.setTranslation( 
        transform.translation().x() + 36.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 36.0f * cos( translationAngle ) );
    }

    // SATURN
    {
        static float translationAngle = 28.0;
        translationAngle += .00070;
        planets["Saturn"]->transform.setTranslation( 
        transform.translation().x() + 72.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 72.0f * cos( translationAngle ) );
    }

    // URANUS
    {
        static float translationAngle = 30.0;
        translationAngle += .00085;
        planets["Uranus"]->transform.setTranslation( 
        transform.translation().x() + 100.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 100.0f * cos( translationAngle ) );
    }

    // NEPTUNE
    {
        static float translationAngle = 46.0;
        translationAngle += .00090;
        planets["Neptune"]->transform.setTranslation( 
        transform.translation().x() + 200.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 200.0f * cos( translationAngle ) );
    }

    // PLUTO
    {
        static float translationAngle = 55.0;
        translationAngle += .000010;
        planets["Pluto"]->transform.setTranslation( 
        transform.translation().x() + 300.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 300.0f * cos( translationAngle ) );
    }
}

void Sun::updateReal()
{

}