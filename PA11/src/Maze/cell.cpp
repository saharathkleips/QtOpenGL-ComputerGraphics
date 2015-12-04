#include "cell.h"

Cell::Cell( btTransform startingState, QString pathToTexture )
    :   UVPhysicsEntity( startingState, 0, "models/UVCube.obj", pathToTexture )
{

}

void Cell::initializeGL()
{
    UVPhysicsEntity::initializeGL();
}

void Cell::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    UVPhysicsEntity::paintGL( camera, projection );
}

void Cell::update()
{
    UVPhysicsEntity::update();
}

void Cell::teardownGL()
{
    UVPhysicsEntity::teardownGL();
}