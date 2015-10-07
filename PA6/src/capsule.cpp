#include "capsule.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 

/**
 * @brief      Default constructor.
 */
Capsule::Capsule()
{
    model = loadObj( QString( "models/capsule.obj" ) );
}

/**
 * @brief      Constructor that accepts path for model and texture.
 *
 * @param[in]  modelPath    Full path to this object's model.
 * @param[in]  texturePath  Full path to this object's texture.
 */
Capsule::Capsule( QString modelPath, QString texturePath )
{
    model = loadObj( path );
}

/**
 * @brief      Destructor for Capsule.
 */
Capsule::~Capsule()
{
    this->teardownGL();
}


//
// INTERFACE IMPLEMENTATIONS ///////////////////////////////////////////////////
// 

/**
 * @brief      Initialize all OpenGL related processes.
 * @details    Loads the shader programs, creates the texture buffer object, 
 * caches the uniform MVP matrices, and creates the VBO and VAO. 
 */
void Capsule::initializeGL()
{
    initializeOpenGLFunctions();

    // Create the Shader for suzanne to use
    program = new QOpenGLShaderProgram();
    program->addShaderFromSourceFile( QOpenGLShader::Vertex, 
        ":/shaders/simple.vs" );
    program->addShaderFromSourceFile( QOpenGLShader::Fragment,
        ":/shaders/simple.fs" );
    program->link();
    program->bind();

    // Texture Buffer Object
    texture = new QOpenGLTexture( 
        QImage( ":/textures/capsule.jpg" ).mirrored() );
    texture->setMinificationFilter( QOpenGLTexture::LinearMipMapLinear );
    texture->setMagnificationFilter( QOpenGLTexture::Linear );

    // Cache the Uniform Locations
    modelWorld = program->uniformLocation( "model_to_world" );
    worldEye = program->uniformLocation( "world_to_eye" );
    eyeClip = program->uniformLocation( "eye_to_clip" );

    // Create a Vertex Buffer Object (vbo)
    vbo.create();
    vbo.bind();
    vbo.setUsagePattern( QOpenGLBuffer::StaticDraw );
    vbo.allocate( model, numVertices * sizeof( model[0] ) );

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
                                    Vertex::uvOffset(),
                                    Vertex::UVTupleSize,
                                    Vertex::stride() );

    // Release all (order matters)
    vao.release();
    vbo.release();
    program->release();
}

/**
 * @brief      Draws Capsule to the current context.
 *
 * @param      camera      The current view in use.
 * @param      projection  The current projection in use.
 */
void Capsule::paintGL( Camera3D& camera, QMatrix4x4& projection )
{
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glDepthMask( GL_TRUE );
    glEnable( GL_CULL_FACE );

    program->bind();

    program->setUniformValue( worldEye, camera.toMatrix() );
    program->setUniformValue( eyeClip, projection );

    vao.bind();
    texture->bind();

    program->setUniformValue( modelWorld, transform.toMatrix() );

    glDrawArrays(   GL_TRIANGLES,
                    0,
                    numVertices );

    texture->release();
    vao.release();
    program->release();
}

/**
 * @brief      Releases all resources used by Capsule.
 */
void Capsule::teardownGL()
{
    vao.destroy();
    vbo.destroy();

    delete texture;
    delete model;
    delete program;
}

//
// MODEL LOADING ///////////////////////////////////////////////////////////////
// 

/**
 * @brief      Loads a model based on a file path.
 * @details    This function uses Assimp to load models, as a result, models of
 * many various types can be loaded.
 * @see        Vertex
 * @param[in]  path  The full path to the model source.
 *
 * @return     The custom Vertex data loaded from the Assimp model.
 */
Vertex* Capsule::loadObj( QString path )
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( path.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );

    aiMesh* mesh = scene->mMeshes[0];

    numVertices = mesh->mNumFaces * 3;
    Vertex* geometry = new Vertex[ numVertices ];

    for( unsigned int i = 0; i < mesh->mNumFaces; i++ )
    {
        const aiFace& face = mesh->mFaces[i];

        for( unsigned int j = 0; j < 3; j++ )
        {
            aiVector3D pos = mesh->mVertices[ face.mIndices[j] ];
            QVector3D position( pos.x, pos.y, pos.z) ;

            aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
            QVector2D uv_coords( uv.x, uv.y );
            
            geometry->setPosition( position );
            geometry->setUV( uv_coords );
            
            geometry++;
        }
    }

    geometry -= mesh->mNumFaces * 3;

    return geometry;
}