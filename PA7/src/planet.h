#ifndef PLANET_H
#define PLANET_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include "renderable.h"
#include "transform3d.h"
#include "camera3d.h"
#include "vertex.h"

class QOpenGLShaderProgram;

class Planet    :   protected QOpenGLFunctions,
                    protected ModelLoader,
                    public Renderable
{
public:
    Planet();
    Planet( QString texturePath );
    Planet( QString texturePath, QString fShaderPath, QString vShaderPath);
    ~Planet();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

    Transform3D transform;
private:
    // OpenGL State Information
    static QOpenGLBuffer vbo;
    QOpenGLVertexArrayObject vao;
    QOpenGLShaderProgram* program;

    // Model Information
    const QString MODEL_PATH = "models/planet.obj";
    static Vertex* model;
    int numVertices;

    // Texture Information
    QString m_texturePath;
    QOpenGLTexture* texture;

    // Shader Information
    QString m_fShaderPath;
    QString m_vShaderPath
    int modelWorld;
    int worldEye;
    int eyeClip;
};

#endif  //  PLANET