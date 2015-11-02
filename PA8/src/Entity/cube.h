#ifndef CUBE_H
#define CUBE_H

#include <QString>

#include "physicsEntity.h"

class Cube  :   public PhysicsEntity
{
public:
    Cube( QString pathToModel = "models/cube.obj", 
          QString pathToTexture = "textures/texture.png",
          btScalar mass = 1,
          btTransform startingState = btTransform( btQuaternion( 0, 0, 0, 1 ), 
            btVector3( 0, 6, 0 ) ) );
    ~Cube();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  CUBE_H