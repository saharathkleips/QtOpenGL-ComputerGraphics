#ifndef PHYSICS_ENTITY
#define PHYSICS_ENTITY

#include "baseEntity.h"
#include <btBulletDynamicsCommon.h>

class PhysicsEntity     :   public BaseEntity
{
public:
    btRigidBody* RigidBody;
    QMatrix4x4 BTransform;

protected:
    PhysicsEntity( btTransform startingState, btScalar mass,
        QString pathToModel, QString pathToTexture );
    ~PhysicsEntity();

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

#endif  //  PHYSICS_ENTITY