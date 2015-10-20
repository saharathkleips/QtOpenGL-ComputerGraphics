#ifndef BOARD_H
#define BOARD_H

#include <QString>

#include "baseEntity.h"

class Board  :   public BaseEntity
{
public:
    Board( QString pathToModel = "models/board.obj", 
        QString pathToTexture = "textures/texture.png" );
    ~Board();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  BOARD_H