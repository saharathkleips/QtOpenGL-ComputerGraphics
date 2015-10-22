#ifndef PHYSICS_ENTITY
#define PHYSICS_ENTITY

#include <QString>

#include "3D/modelLoader.h"

#include <btBulletDynamicsCommon.h>

class PhysicsEntity
{
protected:
    PhysicsEntity( QString pathToModel );
    ~PhysicsEntity();
public:
    btRigidBody* getRigidBody();

    btScalar Mass;
    btVector3 Inertia;
    
    btRigidBody* RigidBody;

private:
    btTriangleMesh* m_triMesh;
    btCollisionShape* m_collisionShape;
    btDefaultMotionState* m_motionState;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  PHYSICS_ENTITY