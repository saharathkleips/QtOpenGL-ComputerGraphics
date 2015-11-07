#ifndef COLOR_ENTITY
#define COLOR_ENTITY

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include "3D/renderable.h"
#include "3D/modelLoader.h"
#include "3D/transform3d.h"
#include "3D/colorVertex.h"

class ColorEntity    :   public Renderable
{
public:
    Transform3D GTransform;
    
protected:
    ColorEntity( QString pathToModel );
    ~ColorEntity();

    // Renderable Functions
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    virtual void update();
    void teardownGL();

    // OpenGL State Data
    QOpenGLBuffer* m_vbo;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLShaderProgram* m_program;

    // Model Information
    QString m_pathToModel;
    ColorVertex* m_model;
    int m_numVertices;

    // Shader Information
    const QString PATH_TO_V_SHADER = ":/shader/simple.vs";
    const QString PATH_TO_F_SHADER = ":/shader/simple.fs";
    int m_modelWorld;
    int m_worldEye;
    int m_eyeClip;
};

#endif  //  ColorEntity