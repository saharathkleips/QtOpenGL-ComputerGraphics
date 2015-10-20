#ifndef CYLINDAR_H
#define CYLINDAR_H

#include <QString>

#include "baseEntity.h"

class Cylindar  :   public BaseEntity
{
public:
    Cylindar( QString pathToModel = "models/cylindar32.obj", 
        QString pathToTexture = "textures/texture.png" );
    ~Cylindar();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  CYLINDAR_H