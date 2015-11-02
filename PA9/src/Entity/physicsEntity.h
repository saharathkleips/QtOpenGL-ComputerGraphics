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

class PhysicsEntity     :   public BaseEntity
{
public:
    // CAN WE MAKE INERTIA PRIVATE?
    btVector3 Inertia;
    btRigidBody* RigidBody;
    QMatrix4x4 BTransform;

protected:
    PhysicsEntity( btTransform startingState, btScalar mass,
        QString pathToModel, QString pathToTexture );
    ~PhysicsEntity();

    // Renderable Functions
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    virtual void update();

private:
    // Bullet Information
    btTriangleMesh* m_triMesh;
    btCollisionShape* m_collisionShape;

    btDefaultMotionState* m_motionState;
    btScalar m_mass;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  PHYSICS_ENTITY