#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "camera3d.h"

class Renderable    :   protected QOpenGLFunctions
{
public:
    virtual void initializeGL() = 0;
    virtual void paintGL( Camera3D& camera, QMatrix4x4& projection ) = 0;
    virtual void update() = 0;
    virtual void teardownGL() = 0;
};

#endif  //  RENDERABLE