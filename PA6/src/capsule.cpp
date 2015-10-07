#include "capsule.h"
//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Capsule::Capsule()
{
    model = loadObj( QString( "models/capsule.obj" ) );
}

Capsule::Capsule( QString path )
{
    model = loadObj( path );
}


Capsule::~Capsule()
{
    this->teardownGL();
}


//
// INTERFACE IMPLEMENTATIONS ///////////////////////////////////////////////////
// 

 
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