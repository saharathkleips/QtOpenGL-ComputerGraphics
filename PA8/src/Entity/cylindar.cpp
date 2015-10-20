#include "cylindar.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


Cylindar::Cylindar( QString pathToModel, QString pathToTexture )
    :   BaseEntity( pathToModel, pathToTexture )
{
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
//


void Cylindar::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );
    BaseEntity::paintGL( camera, projection );
}

void Cylindar::update()
{
}