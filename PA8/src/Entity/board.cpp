#include "board.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


Board::Board( QString pathToModel, QString pathToTexture, btScalar mass,
    btTransform startingState )
    :   PhysicsEntity( pathToModel, pathToTexture, mass, startingState )
{
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
//


void Board::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glDisable( GL_CULL_FACE );
    PhysicsEntity::paintGL( camera, projection );
}

void Board::update()
{
}