#ifndef COLOR_PHYSICS_ENTITY
#define COLOR_PHYSICS_ENTITY

#include "colorEntity.h"
#include <btBulletDynamicsCommon.h>

class ColorPhysicsEntity     :   public ColorEntity
{
public:
    btRigidBody* RigidBody;
    QMatrix4x4 BTransform;

protected:
    ColorPhysicsEntity( btTransform startingState, btScalar mass,
        QString pathToModel );
    ~ColorPhysicsEntity();

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

#endif  //  COLOR_PHYSICS_ENTITY