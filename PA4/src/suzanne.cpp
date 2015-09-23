#include "suzanne.h"

//
// CONSTRUCTORS ////////////////////////////////////////////////////////////////
// 


Suzanne::Suzanne()
{
    model = loadObj( QString(":/models/suzanne.obj") );
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
    QVector<unsigned int> vertexIndices, uvIndices, normalIndices;
    QVector<QVector3D> temp_vertices;
    QVector<QVector2D> temp_uvs;
    QVector<QVector3D> temp_normals;
    bool hasTextures = false;
    bool hasNormals = false;

    QFile file( path );
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Error: " << qPrintable( file.errorString() );
        QApplication::instance()->quit();
    }

    QTextStream in( &file );
    while( !in.atEnd() )
    {
        QString line = in.readLine();
        QStringList fields = line.split( " " );
        
        if( fields[0] == "v" )  // Vertex
        {
            QVector3D v;
            v.setX( fields[1].toFloat() );
            v.setY( fields[2].toFloat() );
            v.setZ( fields[3].toFloat() );
            temp_vertices.push_back( v );
        }
        else if(fields[0] == "vt" ) // Texture coordinate of one vertex
        {
            hasTextures = true;
            QVector2D uv;
            uv.setX( fields[1].toFloat() );
            uv.setY( fields[2].toFloat() );
            temp_uvs.push_back( uv );
        }
        else if( fields[0] == "vn" ) // Normal of one vertex
        {
            hasNormals = true;
            QVector3D n;
            n.setX( fields[1].toFloat() );
            n.setY( fields[2].toFloat() );
            n.setZ( fields[3].toFloat() );
            temp_normals.push_back( n );
        }
        else if( fields[0] == "f" ) // Face
        {
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            (void)uvIndex;      //@todo
            (void)normalIndex;  //@todo

            if( !hasTextures && !hasNormals )
            {
                vertexIndex[0] = fields[1].toUInt();
                vertexIndex[1] = fields[2].toUInt();
                vertexIndex[2] = fields[3].toUInt();
            }
            else if( hasTextures && !hasNormals )
            {
                QStringList args1 = fields[1].split("/");
                QStringList args2 = fields[2].split("/");
                QStringList args3 = fields[3].split("/");

                vertexIndex[0] = args1[0].toUInt();
                uvIndex[0]     = args1[1].toUInt();
                vertexIndex[1] = args2[0].toUInt();
                uvIndex[1]     = args2[1].toUInt();
                vertexIndex[2] = args3[0].toUInt();
                uvIndex[2]     = args3[1].toUInt();
            }
            else if( !hasTextures && hasNormals )
            {
                QStringList args1 = fields[1].split("//");
                QStringList args2 = fields[2].split("//");
                QStringList args3 = fields[3].split("//");

                vertexIndex[0] = args1[0].toUInt();
                normalIndex[0] = args1[1].toUInt();
                vertexIndex[1] = args2[0].toUInt();
                normalIndex[1] = args2[1].toUInt();
                vertexIndex[2] = args3[0].toUInt();
                normalIndex[2] = args3[1].toUInt();
            }
            else if( hasTextures && hasNormals )
            {
                QStringList args1 = fields[1].split("/");
                QStringList args2 = fields[2].split("/");
                QStringList args3 = fields[3].split("/");

                vertexIndex[0] = args1[0].toUInt();
                uvIndex[0]     = args1[1].toUInt();
                normalIndex[0] = args1[2].toUInt();
                vertexIndex[1] = args2[0].toUInt();
                uvIndex[1]     = args2[1].toUInt();
                normalIndex[1] = args2[2].toUInt();
                vertexIndex[2] = args3[0].toUInt();
                uvIndex[2]     = args3[1].toUInt();
                normalIndex[2] = args3[2].toUInt();
            }

            vertexIndices.push_back( vertexIndex[0] );
            vertexIndices.push_back( vertexIndex[1] );
            vertexIndices.push_back( vertexIndex[2] );
        }
    }

    numVertices = vertexIndices.size();
    Vertex* geometry = new Vertex[ vertexIndices.size() ];
    for( int i = 0; i < vertexIndices.size(); i++ )
    {
        unsigned int vertexIndex = vertexIndices[i];
        QVector3D position(
            temp_vertices[vertexIndex - 1].x(),
            temp_vertices[vertexIndex - 1].y(),
            temp_vertices[vertexIndex - 1].z()
            );
        QVector3D color(
            1.0f / ( ( i % 2 ) + 1.0f ),    // R
            1.0f / ( ( i % 4 ) + 1.0f ),    // G
            1.0f / ( ( i % 6 ) + 1.0f )     // B
            );
        geometry[i] = Vertex( position, color );
    }

    return geometry;
}