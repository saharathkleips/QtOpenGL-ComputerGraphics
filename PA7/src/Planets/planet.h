#ifndef PLANET_H
#define PLANET_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QDebug>

#include "../renderable.h"
#include "../modelLoader.h"
#include "../transform3d.h"
#include "../camera3d.h"
#include "../vertex.h"

class QOpenGLShaderProgram;

class Planet    :   public Renderable,
                    protected ModelLoader
{
protected:
    Planet();
    Planet( QString texturePath );
    ~Planet();

public:
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    virtual void update();
    void teardownGL();

    // Planet Information
    Transform3D transform;
    static bool SCALED;

private:
    // OpenGL State Information
    static QOpenGLBuffer* vbo;
    static QOpenGLVertexArrayObject* vao;
    static QOpenGLShaderProgram* program;

    // Model Information
    const QString MODEL_PATH = "models/planet.obj";
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

#endif  //  PLANET_H