#ifndef SKYBOX_H
#define SKYBOX_H

#include "Entity/uvEntity.h"

class Skybox    :   public UVEntity
{
public:
    Skybox();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
};

#endif  //  SKYBOX_H