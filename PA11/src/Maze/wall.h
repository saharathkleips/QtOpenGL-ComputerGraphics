#ifndef WALL_ENTITY
#define WALL_ENTITY

#include <btBulletDynamicsCommon.h>

class Wall
{
public:
    Wall( btVector3 size, btVector3 location );
    ~Wall();
    btRigidBody* RigidBody;

private:
    // Bullet Information
    btTriangleMesh* m_triMesh;
    btCollisionShape* m_collisionShape;
    btDefaultMotionState* m_motionState;
    btVector3 m_inertia;
    btScalar m_mass;
    btRigidBody::btRigidBodyConstructionInfo* m_rigidBodyCI;
};

#endif  //  WALL_ENTITY