#ifndef PHYSICS_ENTITY
#define PHYSICS_ENTITY

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include "3D/renderable.h"
#include "3D/modelLoader.h"
#include "3D/vertex.h"

#include <btBulletDynamicsCommon.h>

class PhysicsEntity     :   public Renderable
{
public:
    btVector3 Inertia;
    btRigidBody* RigidBody;
    QMatrix4x4 Transform;

protected:
    PhysicsEntity( QString pathToModel, QString pathToTexture, btScalar mass );
    ~PhysicsEntity();

    // Renderable Functions
    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    virtual void update();
    void teardownGL();

private:
    // OpenGL State Data
    QOpenGLBuffer* m_vbo;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLShaderProgram* m_program;

    // Model Information
    QString m_pathToModel;
    Vertex* m_model;
    int m_numVertices;

    // Texture Information
    QString m_pathToTexture;
    QOpenGLTexture* m_texture;

    // Shader Information
    const QString PATH_TO_V_SHADER = ":/shader/simple.vs";
    const QString PATH_TO_F_SHADER = ":/shader/simple.fs";
    int m_modelWorld;
    int m_worldEye;
    int m_eyeClip;

    // Bullet Information
    btTriangleMesh* m_triMesh;
    btCollisionShape* m_collisionShape;
    btDefaultMotionState* m_motionState;
    btScalar m_mass;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  PHYSICS_ENTITY