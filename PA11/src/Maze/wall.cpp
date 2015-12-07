#include "wall.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//

/**
 * @brief      Constructor for Wall.
 *
 * @param[in]  size      The size of the wall.
 * @param[in]  location  The location of the wall.
 */
Wall::Wall( btVector3 size, btVector3 location )
{
    m_collisionShape = new btBoxShape( size );

    m_motionState = new btDefaultMotionState( btTransform(btQuaternion(0,0,0,1), location));

    m_inertia = btVector3( 0, 0, 0 );
    m_mass = 0;

    m_collisionShape->calculateLocalInertia( m_mass, m_inertia );

    m_rigidBodyCI = new btRigidBody::btRigidBodyConstructionInfo( 
        m_mass, m_motionState, m_collisionShape, m_inertia );

    RigidBody = new btRigidBody( *m_rigidBodyCI );
}

/**
 * @brief      Destructor for Wall.
 */
Wall::~Wall()
{
    delete m_triMesh;
    delete m_collisionShape;
    delete m_motionState;
    delete m_rigidBodyCI;
    delete RigidBody;
}