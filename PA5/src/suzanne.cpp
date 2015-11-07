#include "suzanne.h"

//@todo COMMENT!
//@todo refactor "suzanne" test model loader into a real model loader

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Suzanne::Suzanne()
{
    model = loadObj( QString( "models/suzanne.obj" ) );
}

Suzanne::Suzanne( QString path )
{
    model = loadObj( path );
    transform.setScale( .07 );
}


Suzanne::~Suzanne()
{
    this->teardownGL();
}


//
// INTERFACE IMPLEMENTATIONS ///////////////////////////////////////////////////
// 


void Suzanne::initializeGL()
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
                                    Vertex::colorOffset(),
                                    Vertex::ColorTupleSize,
                                    Vertex::stride() );

    // Release all (order matters)
    vao.release();
    vbo.release();
    program->release();
}


void Suzanne::paintGL( Camera3D& camera, QMatrix4x4& projection )
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
                    numVertices );
    vao.release();

    program->release();
}


void Suzanne::teardownGL()
{
    vao.destroy();
    vbo.destroy();
    delete program;
}

//
// MODEL LOADING ///////////////////////////////////////////////////////////////
// 

Vertex* Suzanne::loadObj( QString path )
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( path.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );


    aiMesh** mesh = new aiMesh*[scene->mNumMeshes];

    for( unsigned int i = 0; i < scene->mNumMeshes; i++ )
    {
        mesh[i] = scene->mMeshes[i];

        for( unsigned int j = 0; j < mesh[i]->mNumFaces; j++ )
        {
            numVertices += mesh[i]->mFaces[j].mNumIndices;
        }
    }

    Vertex* geometry = new Vertex[ numVertices ];

    for( unsigned int h = 0; h < scene->mNumMeshes; h++ )
    {
        for( unsigned int i = 0; i < mesh[h]->mNumFaces; i++ )
        {
            const aiFace& face = mesh[h]->mFaces[i];
            const aiMaterial* mtl = scene->mMaterials[ mesh[h]->mMaterialIndex ];

            for( unsigned int j = 0; j < 3; j++ )
            {
                aiVector3D pos = mesh[h]->mVertices[ face.mIndices[j] ];
                QVector3D position( pos.x, pos.y, pos.z) ;
                
                QVector3D color( 255.0, 165.0, 0.0 );
                aiColor4D diffuse;
                if( AI_SUCCESS == aiGetMaterialColor( 
                    mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse ) )
                {
                    color.setX( diffuse.r );
                    color.setY( diffuse.g );
                    color.setZ( diffuse.b );
                }

                geometry->setPosition( position );
                geometry->setColor( color );

                geometry++;
            }
        }
    }

    geometry -= numVertices;

    return geometry;
}