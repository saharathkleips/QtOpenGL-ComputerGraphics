#ifndef UV_ENTITY
#define UV_ENTITY

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include "3D/renderable.h"
#include "3D/modelLoader.h"
#include "3D/transform3d.h"
#include "3D/uvVertex.h"

class UVEntity    :   public Renderable
{
public:
    Transform3D GTransform;
    
protected:
    UVEntity( QString pathToModel, QString pathToTexture );
    ~UVEntity();

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
    UVVertex* m_model;
    int m_numVertices;

    // Texture Information
    QString m_pathToTexture;
    QOpenGLTexture* m_texture;

    // Shader Information
    const QString PATH_TO_V_SHADER = ":/shader/uvShader.vs";
    const QString PATH_TO_F_SHADER = ":/shader/uvShader.fs";
    int m_modelWorld;
    int m_worldEye;
    int m_eyeClip;
};

#endif  //  UV_ENTITY