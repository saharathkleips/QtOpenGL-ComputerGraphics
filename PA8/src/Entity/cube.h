#ifndef CUBE_H
#define CUBE_H

#include <QString>

#include "baseEntity.h"

class Cube  :   public BaseEntity
{
public:
    Cube( QString pathToModel = "models/cube.obj", 
        QString pathToTexture = "textures/texture.png" );
    ~Cube();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  CUBE_H