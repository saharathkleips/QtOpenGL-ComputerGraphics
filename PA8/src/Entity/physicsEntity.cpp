#include "physicsEntity.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//


PhysicsEntity::PhysicsEntity( QString pathToModel )
{
    ModelLoader::loadTriMesh( pathToModel, m_triMesh );
    m_collisionShape = new btBvhTriangleMeshShape( m_triMesh, true );
    m_motionState = new btDefaultMotionState( btTransform( 
        btQuaternion( 0, 0, 0, 1 ), btVector3( 0, -1, 0 ) ) );
    Mass = 0;
    Inertia = btVector3( 0, 0, 0 );

    m_collisionShape->calculateLocalInertia( Mass, Inertia );
    m_rigidBodyCI = new btRigidBody::btRigidBodyConstructionInfo( 
        Mass, m_motionState, m_collisionShape, Inertia );
    RigidBody = new btRigidBody( *m_rigidBodyCI );
}

PhysicsEntity::~PhysicsEntity()
{
    delete m_triMesh;
    delete m_collisionShape;
    delete m_motionState;
    delete m_rigidBodyCI;
    delete RigidBody;
}