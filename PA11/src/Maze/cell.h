#ifndef CELL_H
#define CELL_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

#include <QMatrix4x4>
#include <QString>

#include <btBulletDynamicsCommon.h>

#include "3D/renderable.h"
#include "3D/modelLoader.h"
#include "3D/uvVertex.h"
#include "Controls/camera3d.h"

enum Texture
{
    RockWall1,
    RockWall2,
    RockWall3,
    RockWall4,
    RockWall5,
    DirtFloor1
};

class Cell  :   public Renderable
{
public:
    Cell( btTransform startingState, Texture selectedTexture );
    ~Cell();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();

    static Texture getRandomRockWall();

    btRigidBody* RigidBody;
    QMatrix4x4 Transform;

private:
    // OpenGL State Data
    static QOpenGLBuffer* m_vbo;
    static QOpenGLVertexArrayObject* m_vao;
    static QOpenGLShaderProgram* m_program;

    // Model Information
    const QString PATH_TO_MODEL = "models/UVCube.obj";
    static UVVertex* m_model;
    static int m_numVertices;

    // Texture Information
    Texture m_selectedTexture;
    static QOpenGLTexture* m_rockWallTexture1;
    static QOpenGLTexture* m_rockWallTexture2;
    static QOpenGLTexture* m_rockWallTexture3;
    static QOpenGLTexture* m_rockWallTexture4;
    static QOpenGLTexture* m_rockWallTexture5;
    static QOpenGLTexture* m_floorTexture1;

    // Shader Information
    const QString PATH_TO_V_SHADER = ":/shader/uvShader.vs";
    const QString PATH_TO_F_SHADER = ":/shader/uvShader.fs";
    static int m_modelWorld;
    static int m_worldEye;
    static int m_eyeClip;

    // Bullet Information
    static btTriangleMesh* m_triMesh;
    static btCollisionShape* m_collisionShape;

    btDefaultMotionState* m_motionState;
    btVector3 m_inertia;
    const btScalar MASS = 0;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  CELL_H