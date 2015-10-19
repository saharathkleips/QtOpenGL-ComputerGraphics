#include "rings.h"

//
// STATIC VARIABLE INITILIZATION ///////////////////////////////////////////////
// 
bool Rings::SCALED = true;
QOpenGLBuffer* Rings::vbo = NULL;
QOpenGLVertexArrayObject* Rings::vao = NULL;
QOpenGLShaderProgram* Rings::program = NULL;
Vertex* Rings::model = NULL;
int Rings::numVertices = -1;
int Rings::modelWorld = -1;
int Rings::worldEye = -1;
int Rings::eyeClip = -1;

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Rings::Rings()
{
    m_texturePath = ":/texture/saturnringmap.jpg";
    if( model == NULL )
        loadModel( MODEL_PATH, model, numVertices );
}

Rings::Rings( QString texturePath )
    :   m_texturePath( texturePath )
{
    if( model == NULL )
    {
        loadModel( MODEL_PATH, model, numVertices );
    }
}

Rings::~Rings()
{
    this->teardownGL();
}

//
// RENDERABLE FUNCTIONS ////////////////////////////////////////////////////////
// 

/**
 * @brief      Initializes all OpenGL related processes.
 * @details    Loads the shader programs
 */
void Rings::initializeGL()
{
    initializeOpenGLFunctions();
    // Create the shader this ring will be using
    if( program == NULL )
    {    
        program = new QOpenGLShaderProgram();
        program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
            V_SHADER_PATH );
        program->addShaderFromSourceFile( QOpenGLShader::Fragment, 
            F_SHADER_PATH );
        program->link();
        program->bind();
        
        // Cache the Uniform Locations
        modelWorld = program->uniformLocation( "model_to_world" );
        worldEye = program->uniformLocation( "world_to_eye" );
        eyeClip = program->uniformLocation( "eye_to_clip" );

    }
    else
        program->bind();

    // Create Texture Buffer Object
    texture = new QOpenGLTexture( QImage( m_texturePath ).mirrored() );
    
    texture->setMinificationFilter( QOpenGLTexture::LinearMipMapLinear );
    texture->setMagnificationFilter( QOpenGLTexture::Linear );

    // Create the Vertex Buffer Object only if it's not already created
    if( vbo == NULL )
    {
        vbo = new QOpenGLBuffer();
        vbo->create();
        vbo->bind();
        vbo->setUsagePattern( QOpenGLBuffer::StaticDraw );
        vbo->allocate( model, numVertices * sizeof( model[0] ) );
    }
    else
        vbo->bind();

    // Create the Vertex Array Object only if it's not already created
    if( vao == NULL )
    {
        vao = new QOpenGLVertexArrayObject();
        vao->create();
        vao->bind();
        program->enableAttributeArray( 0 );
        program->enableAttributeArray( 1 );
        program->setAttributeBuffer(    0,
                                        GL_FLOAT,
                                        Vertex::positionOffset(),
                                        Vertex::PositionTupleSize,
                                        Vertex::stride() );
        program->setAttributeBuffer(    1,
                                        GL_FLOAT,
                                        Vertex::uvOffset(),
                                        Vertex::UVTupleSize,
                                        Vertex::stride() );
    }
    else
        vao->bind();

    // Release all in order
    vao->release();
    vbo->release();
    texture->release();
    program->release();
}

void Rings::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );

    program->bind();

    program->setUniformValue( worldEye, camera.toMatrix() );
    program->setUniformValue( eyeClip, projection );

    vao->bind();
    texture->bind();

    program->setUniformValue( modelWorld, transform.toMatrix() );

    glDrawArrays( GL_TRIANGLES, 0, numVertices );

    texture->release();
    vao->release();
    program->release();
}

void Rings::update()
{
}

void Rings::teardownGL()
{
    delete texture;
}