#ifndef RENDERABLE
#define RENDERABLE

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <QMatrix4x4>

#include "transform3d.h"
#include "camera3d.h"

class QOpenGLShaderProgram;

class Renderable    :   protected QOpenGLFunctions
{
public:
    virtual void initializeGL() = 0;
    virtual void paintGL( Camera3D& camera, QMatrix4x4& projection ) = 0;
    virtual void teardownGL() = 0;

    // Transformation Matrix
    Transform3D transform;

protected:
    // OpenGL State Information
    QOpenGLBuffer vbo;
    QOpenGLVertexArrayObject vao;
    QOpenGLShaderProgram* program;

    // Shader Information
    int modelWorld;
    int worldEye;
    int eyeClip;
};

#endif  //  RENDERABLE