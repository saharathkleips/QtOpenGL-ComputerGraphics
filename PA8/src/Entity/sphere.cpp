#include "sphere.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


Sphere::Sphere( QString pathToModel, QString pathToTexture )
    :   BaseEntity( pathToModel, pathToTexture )
{
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
//


void Sphere::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );
    BaseEntity::paintGL( camera, projection );
}

void Sphere::update()
{
}