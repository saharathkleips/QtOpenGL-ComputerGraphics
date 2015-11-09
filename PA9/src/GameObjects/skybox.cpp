#include "skybox.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Skybox::Skybox()
    :   UVEntity( "models/skybox.obj", "textures/room.jpg" )
{
    GTransform.setScale( 400.0f );
}


void Skybox::paintGL(Camera3D& camera, QMatrix4x4& projection)
{
    UVEntity::paintGL(camera, projection);
}
