#include "cell.h"

//
// STATIC INITIALIZATION ///////////////////////////////////////////////////////
//
QOpenGLBuffer* Cell::m_vbo = NULL;
QOpenGLVertexArrayObject* Cell::m_vao = NULL;
QOpenGLShaderProgram* Cell::m_program = NULL;
UVVertex* Cell::m_model = NULL;
int Cell::m_numVertices = -1;
QOpenGLTexture* Cell::m_rockWallTexture[5] = { NULL, NULL, NULL, NULL, NULL };
QOpenGLTexture* Cell::m_dirtFloorTexture = NULL;
QOpenGLTexture* Cell::m_iceWallTexture[5] = { NULL, NULL, NULL, NULL, NULL };
QOpenGLTexture* Cell::m_snowFloorTexture = NULL;
int Cell::m_modelWorld = -1;
int Cell::m_worldEye = -1;
int Cell::m_eyeClip = -1;
btTriangleMesh* Cell::m_triMesh = NULL;
btCollisionShape* Cell::m_collisionShape = NULL;

Cell::Cell( btTransform startingState, Texture selectedTexture )
    :   m_selectedTexture( selectedTexture )
{
    if( m_model == NULL )
        ModelLoader::loadUVModel( PATH_TO_MODEL, m_model, m_numVertices );
    if( m_triMesh == NULL )
        ModelLoader::loadTriMesh( PATH_TO_MODEL, m_triMesh );
    if( m_collisionShape == NULL )
        m_collisionShape = new btBvhTriangleMeshShape( m_triMesh, true );

    m_motionState = new btDefaultMotionState( startingState );
    m_inertia = btVector3( 0, 0, 0 );

    m_collisionShape->calculateLocalInertia( MASS, m_inertia );
    m_rigidBodyCI = new btRigidBody::btRigidBodyConstructionInfo(
        MASS, m_motionState, m_collisionShape, m_inertia );

    RigidBody = new btRigidBody( *m_rigidBodyCI );

    RigidBody->setCollisionFlags( RigidBody->getCollisionFlags() | 
        btCollisionObject::CF_KINEMATIC_OBJECT );
    RigidBody->setActivationState( DISABLE_DEACTIVATION );
}

Cell::~Cell()
{
    delete m_rigidBodyCI;
    delete m_motionState;
    delete RigidBody;
}

void Cell::initializeGL()
{
    initializeOpenGLFunctions();

    if( m_program == NULL )
    {
        // Create the shader this entity will use
        m_program = new QOpenGLShaderProgram();
        m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
            PATH_TO_V_SHADER );
        m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, 
            PATH_TO_F_SHADER );
        m_program->link();
        m_program->bind();

        // Cache the Uniform Locations
        m_modelWorld = m_program->uniformLocation( "model_to_world" );
        m_worldEye = m_program->uniformLocation( "world_to_eye" );
        m_eyeClip = m_program->uniformLocation( "eye_to_clip" );
    }
    else
        m_program->bind();

    if( m_rockWallTexture[0] == NULL )
    {
        m_rockWallTexture[0] = new QOpenGLTexture( 
            QImage( "textures/Cube_RockWall1.jpg" ).mirrored() );
        m_rockWallTexture[0]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_rockWallTexture[0]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_rockWallTexture[1] == NULL )
    {
        m_rockWallTexture[1] = new QOpenGLTexture( 
            QImage( "textures/Cube_RockWall2.jpg" ).mirrored() );
        m_rockWallTexture[1]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_rockWallTexture[1]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_rockWallTexture[2] == NULL )
    {
        m_rockWallTexture[2] = new QOpenGLTexture( 
            QImage( "textures/Cube_RockWall3.jpg" ).mirrored() );
        m_rockWallTexture[2]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_rockWallTexture[2]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_rockWallTexture[3] == NULL )
    {
        m_rockWallTexture[3] = new QOpenGLTexture( 
            QImage( "textures/Cube_RockWall4.jpg" ).mirrored() );
        m_rockWallTexture[3]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_rockWallTexture[3]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_rockWallTexture[4] == NULL )
    {
        m_rockWallTexture[4] = new QOpenGLTexture( 
            QImage( "textures/Cube_RockWall5.jpg" ).mirrored() );
        m_rockWallTexture[4]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_rockWallTexture[4]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_dirtFloorTexture == NULL )
    {
        m_dirtFloorTexture = new QOpenGLTexture( 
            QImage( "textures/Cube_DirtFloor.jpg" ).mirrored() );
        m_dirtFloorTexture->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_dirtFloorTexture->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_iceWallTexture[0] == NULL )
    {
        m_iceWallTexture[0] = new QOpenGLTexture( 
            QImage( "textures/Cube_IceWall1.jpg" ).mirrored() );
        m_iceWallTexture[0]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_iceWallTexture[0]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_iceWallTexture[1] == NULL )
    {
        m_iceWallTexture[1] = new QOpenGLTexture( 
            QImage( "textures/Cube_IceWall2.jpg" ).mirrored() );
        m_iceWallTexture[1]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_iceWallTexture[1]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_iceWallTexture[2] == NULL )
    {
        m_iceWallTexture[2] = new QOpenGLTexture( 
            QImage( "textures/Cube_IceWall3.jpg" ).mirrored() );
        m_iceWallTexture[2]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_iceWallTexture[2]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_iceWallTexture[3] == NULL )
    {
        m_iceWallTexture[3] = new QOpenGLTexture( 
            QImage( "textures/Cube_IceWall4.jpg" ).mirrored() );
        m_iceWallTexture[3]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_iceWallTexture[3]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_iceWallTexture[4] == NULL )
    {
        m_iceWallTexture[4] = new QOpenGLTexture( 
            QImage( "textures/Cube_IceWall5.jpg" ).mirrored() );
        m_iceWallTexture[4]->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_iceWallTexture[4]->setMagnificationFilter( QOpenGLTexture::Linear );
    }
    if( m_snowFloorTexture == NULL )
    {
        m_snowFloorTexture = new QOpenGLTexture( 
            QImage( "textures/Cube_SnowFloor.jpg" ).mirrored() );
        m_snowFloorTexture->setMinificationFilter( 
            QOpenGLTexture::LinearMipMapLinear );
        m_snowFloorTexture->setMagnificationFilter( QOpenGLTexture::Linear );
    }


    if( m_vbo == NULL )
    {
        m_vbo = new QOpenGLBuffer();
        m_vbo->create();
        m_vbo->bind();
        m_vbo->setUsagePattern( QOpenGLBuffer::StaticDraw );
        m_vbo->allocate( m_model, m_numVertices * sizeof( m_model[0] ) );
    }
    else
        m_vbo->bind();

    if( m_vao == NULL )
    {
        m_vao = new QOpenGLVertexArrayObject();
        m_vao->create();
        m_vao->bind();
        m_program->enableAttributeArray( 0 );
        m_program->enableAttributeArray( 1 );
        m_program->setAttributeBuffer(  0,
                                        GL_FLOAT,
                                        UVVertex::positionOffset(),
                                        UVVertex::PositionTupleSize,
                                        UVVertex::stride() );
        m_program->setAttributeBuffer(  1,
                                        GL_FLOAT,
                                        UVVertex::uvOffset(),
                                        UVVertex::UVTupleSize,
                                        UVVertex::stride() );
    }
    else
        m_vao->bind();

    m_vao->release();
    m_vbo->release();
    m_program->release();
}

void Cell::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glDisable( GL_CULL_FACE );

    QOpenGLTexture* texture = NULL;
    switch( m_selectedTexture )
    {
        case Texture::RockWall1:
            texture = m_rockWallTexture[0];
            break;
        case Texture::RockWall2:
            texture = m_rockWallTexture[1];
            break;
        case Texture::RockWall3:
            texture = m_rockWallTexture[2];
            break;
        case Texture::RockWall4:
            texture = m_rockWallTexture[3];
            break;
        case Texture::RockWall5:
            texture = m_rockWallTexture[4];
            break;
        case Texture::DirtFloor:
            texture = m_dirtFloorTexture;
            break;
        case Texture::IceWall1:
            texture = m_iceWallTexture[0];
            break;
        case Texture::IceWall2:
            texture = m_iceWallTexture[1];
            break;
        case Texture::IceWall3:
            texture = m_iceWallTexture[2];
            break;
        case Texture::IceWall4:
            texture = m_iceWallTexture[3];
            break;
        case Texture::IceWall5:
            texture = m_iceWallTexture[4];
            break;
        case Texture::SnowFloor:
            texture = m_snowFloorTexture;
            break;
        default:
            texture = m_snowFloorTexture;
            break;
    }

    m_program->bind();

    m_program->setUniformValue( m_worldEye, camera.toMatrix() );
    m_program->setUniformValue( m_eyeClip, projection );

    m_vao->bind();
    texture->bind();

    m_program->setUniformValue( m_modelWorld, Transform );

    glDrawArrays( GL_TRIANGLES, 0, m_numVertices );

    texture->release();
    m_vao->release();
    m_program->release();
}

void Cell::update()
{
    btScalar rawMatrix[16];
    RigidBody->getWorldTransform().getOpenGLMatrix( rawMatrix );

    QMatrix4x4 newMatrix = QMatrix4x4( rawMatrix ).transposed();

    Transform = newMatrix;
}

void Cell::teardownGL()
{

}

Texture Cell::getRandomRockWall()
{
    int switchVal = rand() % 5;
    switch( switchVal )
    {
        case 0:
            return Texture::RockWall1;
            break;
        case 1:
            return Texture::RockWall2;
            break;
        case 2:
            return Texture::RockWall3;
            break;
        case 3:
            return Texture::RockWall4;
            break;
        case 4:
            return Texture::RockWall5;
            break;
        default:
            return Texture::DirtFloor;
    }
}

Texture Cell::getRandomIceWall()
{
    int switchVal = rand() % 5;
    switch( switchVal )
    {
        case 0:
            return Texture::IceWall1;
            break;
        case 1:
            return Texture::IceWall2;
            break;
        case 2:
            return Texture::IceWall3;
            break;
        case 3:
            return Texture::IceWall4;
            break;
        case 4:
            return Texture::IceWall5;
            break;
        default:
            return Texture::SnowFloor;
    }
}