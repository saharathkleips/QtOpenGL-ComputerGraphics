#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include "Controls/camera3d.h"
#include "3D/transform3d.h"

class Renderable    :   protected QOpenGLFunctions
{
public:
    virtual void initializeGL() = 0;
    virtual void paintGL( Camera3D& camera, QMatrix4x4& projection ) = 0;
    virtual void update() = 0;
    virtual void teardownGL() = 0;

    Transform3D Transform;
};

#endif  //  RENDERABLE