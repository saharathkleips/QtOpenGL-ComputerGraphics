#ifndef UV_PHYSICS_ENTITY
#define UV_PHYSICS_ENTITY

#include "uvEntity.h"
#include <btBulletDynamicsCommon.h>

class UVPhysicsEntity     :   public UVEntity
{
public:
    btRigidBody* RigidBody;
    QMatrix4x4 BTransform;

protected:
    UVPhysicsEntity( btTransform startingState, btScalar mass,
        QString pathToModel, QString pathToTexture );
    ~UVPhysicsEntity();

    // Renderable Functions
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();

private:
    // Bullet Information
    btTriangleMesh* m_triMesh;
    btCollisionShape* m_collisionShape;

    btDefaultMotionState* m_motionState;
    btVector3 m_inertia;
    btScalar m_mass;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  UV_PHYSICS_ENTITY