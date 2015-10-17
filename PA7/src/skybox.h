#ifndef SKYBOX_H
#define SKYBOX_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QDebug>

#include "renderable.h"
#include "modelLoader.h"
#include "transform3d.h"
#include "camera3d.h"
#include "vertex.h"

class QOpenGLShaderProgram;

class Skybox    :   public Renderable,
                    protected ModelLoader
{
public:
    Skybox();
    ~Skybox();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();
private:
    Transform3D transform;
    
    // OpenGL State Information
    QOpenGLBuffer* vbo;
    QOpenGLVertexArrayObject* vao;
    QOpenGLShaderProgram* program;

    // Model Information
    const QString MODEL_PATH = "models/skybox.obj";
    Vertex* model;
    int numVertices;

    // Texture Information
    const QString TEXTURE_PATH = ":/texture/skybox.jpg";
    QOpenGLTexture* texture;

    // Shader Information
    const QString V_SHADER_PATH = ":/shader/simple.vs";
    const QString F_SHADER_PATH = ":/shader/simple.fs";
    int modelWorld;
    int worldEye;
    int eyeClip;
};

#endif  //  SKYBOX_H