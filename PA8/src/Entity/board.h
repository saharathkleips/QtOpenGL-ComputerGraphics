#ifndef BOARD_H
#define BOARD_H

#include <QString>

#include "physicsEntity.h"

class Board  :   public PhysicsEntity
{
public:
    Board( QString pathToModel = "models/board.obj", 
           QString pathToTexture = "textures/texture.png",
           btScalar mass = 0 );
    ~Board();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  BOARD_H