#include "uvPhysicsEntity.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
//

/**
 * @brief      Constructor for a UVPhysicsEntity.
 *
 * @param[in]  startingState  The starting location and rotation of the object.
 * @param[in]  mass           The mass of the object.
 * @param[in]  pathToModel    The path to the object's model.
 * @param[in]  pathToTexture  The path to the object's texture.
 */
UVPhysicsEntity::UVPhysicsEntity( btTransform startingState, btScalar mass,
    QString pathToModel, QString pathToTexture )
    : UVEntity( pathToModel, pathToTexture ), m_mass( mass )
{
    ModelLoader::loadTriMesh( pathToModel, m_triMesh );

    // The object is static, so use BvhTriMesh
    if( mass == 0 )
        m_collisionShape = new btBvhTriangleMeshShape( m_triMesh, true );
    // The object is dynamic, so use ConvexTriMesh
    else
        m_collisionShape = new btConvexTriangleMeshShape( m_triMesh );

    m_motionState = new btDefaultMotionState( startingState );

    m_inertia = btVector3( 0, 0, 0 );

    m_collisionShape->calculateLocalInertia( m_mass, m_inertia );
    m_rigidBodyCI = new btRigidBody::btRigidBodyConstructionInfo( 
        m_mass, m_motionState, m_collisionShape, m_inertia );

    // Makes objects bouncy (Used in Air Hockey)
    // m_rigidBodyCI->m_restitution = 0.95f;

    RigidBody = new btRigidBody( *m_rigidBodyCI );

    if( mass == 0 )
    {
        RigidBody->setCollisionFlags(RigidBody->getCollisionFlags() | 
            btCollisionObject::CF_KINEMATIC_OBJECT);
        RigidBody->setActivationState(DISABLE_DEACTIVATION);
    }
}

/**
 * @brief      Default destructor for UVPhysicsEntity.
 */
UVPhysicsEntity::~UVPhysicsEntity()
{
    delete m_triMesh;
    delete m_collisionShape;
    delete m_motionState;
    delete m_rigidBodyCI;
    delete RigidBody;
}

/**
 * @brief      Overloaded paintGL function.
 * @details    Draws using a BTransform rather than a GTrasform.
 *
 * @param      camera      The camera of the world.
 * @param      projection  The projection of the world.
 */
void UVPhysicsEntity::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    m_program->bind();

    m_program->setUniformValue( m_worldEye, camera.toMatrix() );
    m_program->setUniformValue( m_eyeClip, projection );

    m_vao->bind();
    m_texture->bind();

    m_program->setUniformValue( m_modelWorld, BTransform );

    glDrawArrays( GL_TRIANGLES, 0, m_numVertices );

    m_texture->release();
    m_vao->release();
    m_program->release();
}

/**
 * @brief      Updates the RigidBody based on the dynamics world it is in.
 */
void UVPhysicsEntity::update()
{
    btScalar rawMatrix[16];
    RigidBody->getWorldTransform().getOpenGLMatrix( rawMatrix );

    QMatrix4x4 newMatrix = QMatrix4x4( rawMatrix ).transposed();

    BTransform = newMatrix;
}