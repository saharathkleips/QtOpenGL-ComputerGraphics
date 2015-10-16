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
    // SUN
    {
        transform.rotate( 1.0f, 0, 1, 0 );
    }

    // MERCURY
    {
        static float translationAngle = 0.0;
        translationAngle += .10;
        planets["Mercury"]->transform.setTranslation( 
        transform.translation().x() + 3.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 3.0f * cos( translationAngle ) );
    }

    // VENUS
    {
        static float translationAngle = 0.0;
        translationAngle += .08;
        planets["Venus"]->transform.setTranslation( 
        transform.translation().x() + 6.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 6.0f * cos( translationAngle ) );
    }

    // EARTH
    {
        static float translationAngle = 0.0;
        translationAngle += .06;
        planets["Earth"]->transform.setTranslation( 
        transform.translation().x() + 9.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 9.0f * cos( translationAngle ) );
    }

    // MARS
    {
        static float translationAngle = 0.0;
        translationAngle += .04;
        planets["Mars"]->transform.setTranslation( 
        transform.translation().x() + 12.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 12.0f * cos( translationAngle ) );
    }

    // JUPITER
    {
        static float translationAngle = 0.0;
        translationAngle += .02;
        planets["Jupiter"]->transform.setTranslation( 
        transform.translation().x() + 15.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 15.0f * cos( translationAngle ) );
    }

    // SATURN
    {
        static float translationAngle = 0.0;
        translationAngle += .008;
        planets["Saturn"]->transform.setTranslation( 
        transform.translation().x() + 18.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 18.0f * cos( translationAngle ) );
    }

    // URANUS
    {
        static float translationAngle = 0.0;
        translationAngle += .006;
        planets["Uranus"]->transform.setTranslation( 
        transform.translation().x() + 21.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 21.0f * cos( translationAngle ) );
    }

    // NEPTUNE
    {
        static float translationAngle = 0.0;
        translationAngle += .004;
        planets["Neptune"]->transform.setTranslation( 
        transform.translation().x() + 24.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 24.0f * cos( translationAngle ) );
    }

    // PLUTO
    {
        static float translationAngle = 0.0;
        translationAngle += .002;
        planets["Pluto"]->transform.setTranslation( 
        transform.translation().x() + 27.0f * sin( translationAngle ),
        transform.translation().y(),
        transform.translation().z() + 27.0f * cos( translationAngle ) );
    }

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
}