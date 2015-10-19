#ifndef RINGS_H
#define RINGS_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QDebug>

#include "renderable.h"
#include "modelLoader.h"
#include "transform3d.h"
#include "vertex.h"

class QOpenGLShaderProgram;

class Rings    :   public Renderable,
                    protected ModelLoader
{
public:
    Rings();
    Rings( QString texturePath );
    ~Rings();


    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

    // Rings Information
    Transform3D transform;
    static bool SCALED;

private:
    // OpenGL State Information
    static QOpenGLBuffer* vbo;
    static QOpenGLVertexArrayObject* vao;
    static QOpenGLShaderProgram* program;

    // Model Information
    const QString MODEL_PATH = "models/rings.obj";
    static Vertex* model;
    static int numVertices;

    // Texture Information
    QString m_texturePath;
    QOpenGLTexture* texture;

    // Shader Information
    const QString V_SHADER_PATH = ":/shader/simple.vs";
    const QString F_SHADER_PATH = ":/shader/simple.fs";
    static int modelWorld;
    static int worldEye;
    static int eyeClip;
};

#endif  //  RINGS_H