#ifndef SPHERE_H
#define SPHERE_H

#include <QString>

#include "baseEntity.h"

class Sphere  :   public BaseEntity
{
public:
    Sphere( QString pathToModel = "models/sphere32.obj", 
        QString pathToTexture = "textures/texture.png" );
    ~Sphere();

    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
};

#endif  //  SPHERE_H