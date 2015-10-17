#include "skybox.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Skybox::Skybox()
{
    loadModel( MODEL_PATH, model, numVertices );
    transform.setScale( 500.0f );
}

Skybox::~Skybox()
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
void Skybox::initializeGL()
{
    initializeOpenGLFunctions();
    // Create the shader this planet will be using
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

    // Create Texture Buffer Object
    texture = new QOpenGLTexture( QImage( TEXTURE_PATH ).mirrored() );
    
    texture->setMinificationFilter( QOpenGLTexture::LinearMipMapLinear );
    texture->setMagnificationFilter( QOpenGLTexture::Linear );

    // Create the Vertex Buffer Object only if it's not already created
    vbo = new QOpenGLBuffer();
    vbo->create();
    vbo->bind();
    vbo->setUsagePattern( QOpenGLBuffer::StaticDraw );
    vbo->allocate( model, numVertices * sizeof( model[0] ) );

    // Create the Vertex Array Object only if it's not already created
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

    // Release all in order
    vao->release();
    vbo->release();
    texture->release();
    program->release();
}

void Skybox::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glDisable( GL_CULL_FACE );

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

void Skybox::update()
{
}

void Skybox::teardownGL()
{
    delete vbo;
    delete vao;;
    delete program;
    delete model;
    delete texture;
}