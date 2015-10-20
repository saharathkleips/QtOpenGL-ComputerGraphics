#include "board.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


Board::Board( QString pathToModel, QString pathToTexture )
    :   BaseEntity( pathToModel, pathToTexture )
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
    BaseEntity::paintGL( camera, projection );
}

void Board::update()
{
}