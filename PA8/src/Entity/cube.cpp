#include "cube.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


Cube::Cube( QString pathToModel, QString pathToTexture, btScalar mass,
    btTransform startingState )
    :   PhysicsEntity( pathToModel, pathToTexture, mass, startingState )
{
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
//


void Cube::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );
    PhysicsEntity::paintGL( camera, projection );
}

void Cube::update()
{
}