#include "cube.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor for Cube.
 */
Cube::Cube()
{
}

/**
 * @brief      Destructor for Cube.
 */
Cube::~Cube()
{
    this->teardownGL();
}

//
// INTERFACE IMPLEMENTATIONS ///////////////////////////////////////////////////
// 

/**
 * @brief      Overridden Renderable function.
 * @details    Initializes the OpenGL contexts / states / buffers to draw the
 * Cube.
 */
void Cube::initializeGL()
{
    initializeOpenGLFunctions();

    // Create the Shader for the Cube to use
    program = new QOpenGLShaderProgram();
    program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
        ":/shaders/simple.vs" );
    program->addShaderFromSourceFile( QOpenGLShader::Fragment,
        ":/shaders/simple.fs" );
    program->link();
    program->bind();

    // Cache the Uniform Locations
    modelWorld = program->uniformLocation( "model_to_world" );
    worldEye = program->uniformLocation( "world_to_eye" );
    eyeClip = program->uniformLocation( "eye_to_clip" );

    // Create a Vertex Buffer Object (vbo)
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern( QOpenGLBuffer::StaticDraw );
    vbo.allocate( sg_vertices, sizeof( sg_vertices ) );

    // Create a Vertex Array Object (vao)
    vao.create();
    vao.bind();
    program->enableAttributeArray( 0 );
    program->enableAttributeArray( 1 );
    program->setAttributeBuffer(    0,
                                    GL_FLOAT,
                                    Vertex::positionOffset(),
                                    Vertex::PositionTupleSize,
                                    Vertex::stride() );
    program->setAttributeBuffer(    1,
                                    GL_FLOAT,
                                    Vertex::colorOffset(),
                                    Vertex::ColorTupleSize,
                                    Vertex::stride() );

    // Release all (order matters)
    vao.release();
    vbo.release();
    program->release();
}

/**
 * @brief      Overridden Renderable function.
 * @details    Paints the Cube onto the screen with the proper states and
 * transformations.
 *
 * @param      camera      The camera of the main drawing canvas.
 * @param      projection  The projection of the main drawing canvas.
 */
void Cube::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );

    program->bind();

    program->setUniformValue( worldEye, camera.toMatrix() );
    program->setUniformValue( eyeClip, projection );

    vao.bind();
    program->setUniformValue( modelWorld, transform.toMatrix() );
    glDrawArrays(   GL_TRIANGLES,
                    0,
                    sizeof( sg_vertices ) / sizeof( sg_vertices[0] ) );
    vao.release();

    program->release();
}

/**
 * @brief      Overridden Renderable function.
 * @details    Disposes of all of the OpenGL data for this Cube.
 */
void Cube::teardownGL()
{
    vao.destroy();
    vbo.destroy();
    delete program;
}