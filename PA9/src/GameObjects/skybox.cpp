#include "skybox.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for Skybox.
 */
Skybox::Skybox()
    :   UVEntity( "models/skybox.obj", "textures/room.jpg" )
{
    GTransform.setScale( 400.0f );
}

/**
 * @brief      Overloaded paintGL function.
 *
 * @param      camera      The camera of the world.
 * @param      projection  The current projection of the world.
 */
void Skybox::paintGL(Camera3D& camera, QMatrix4x4& projection)
{
    UVEntity::paintGL(camera, projection);
}
