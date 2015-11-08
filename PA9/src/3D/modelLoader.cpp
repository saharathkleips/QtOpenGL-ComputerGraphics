#include "modelLoader.h"

/**
 * @brief       Loads a UV-based model based on a file path.
 *
 * @param[in]   filePath      The full path to the model source.
 * @param[out]  geometry      The geometry data of the uv model loaded.
 * @param[out]  numVertices   The number of vertices within the uv model.
 *
 * @return     True of the model loaded successfully, false otherwise.
 */
bool ModelLoader::loadUVModel( QString filePath, UVVertex*& geometry, 
    int& numVertices )
{
    numVertices = 0;

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( filePath.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );

    if( scene == NULL )
    {
        qDebug() << importer.GetErrorString();
        return false;
    }

    aiMesh** mesh = new aiMesh*[scene->mNumMeshes];

    for( unsigned int i = 0; i < scene->mNumMeshes; i++ )
    {
        mesh[i] = scene->mMeshes[i];
        for( unsigned int j = 0; j < mesh[i]->mNumFaces; j++ )
        {
            numVertices += mesh[i]->mFaces[j].mNumIndices;
        }
    }

    UVVertex* geo = new UVVertex[ numVertices ];

    for( unsigned int h = 0; h < scene->mNumMeshes; h++ )
    {
        for( unsigned int i = 0; i < mesh[h]->mNumFaces; i++ )
        {
            const aiFace& face = mesh[h]->mFaces[i];

            for( unsigned int j = 0; j < 3; j++ )
            {
                aiVector3D pos = mesh[h]->mVertices[ face.mIndices[j] ];
                QVector3D position( pos.x, pos.y, pos.z) ;

                aiVector3D uv = mesh[h]->mTextureCoords[0][face.mIndices[j]];
                QVector2D uv_coords( uv.x, uv.y );
                
                geo->setPosition( position );
                geo->setUV( uv_coords );
                
                geo++;
            }
        }
    }

    geo -= numVertices;

    geometry = geo;
    return true;
}

/**
 * @brief       Loads a material-based model based on a file path.
 *
 * @param[in]   filePath      The full path to the model source.
 * @param[out]  geometry      The geometry data of the color model loaded.
 * @param[out]  numVertices   The number of vertices within the color model.
 *
 * @return     True of the model loaded successfully, false otherwise.
 */
bool ModelLoader::loadColorModel( QString filePath, ColorVertex*& geometry, 
    int& numVertices )
{
    numVertices = 0;

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( filePath.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );

    if( scene == NULL )
    {
        qDebug() << importer.GetErrorString();
        return false;
    }

    aiMesh** mesh = new aiMesh*[scene->mNumMeshes];

    for( unsigned int i = 0; i < scene->mNumMeshes; i++ )
    {
        mesh[i] = scene->mMeshes[i];
        for( unsigned int j = 0; j < mesh[i]->mNumFaces; j++ )
        {
            numVertices += mesh[i]->mFaces[j].mNumIndices;
        }
    }

    ColorVertex* geo = new ColorVertex[ numVertices ];

    for( unsigned int h = 0; h < scene->mNumMeshes; h++ )
    {
        for( unsigned int i = 0; i < mesh[h]->mNumFaces; i++ )
        {
            const aiFace& face = mesh[h]->mFaces[i];
            const aiMaterial* mtl = scene->mMaterials[ 
                mesh[h]->mMaterialIndex ];

            for( unsigned int j = 0; j < 3; j++ )
            {
                aiVector3D pos = mesh[h]->mVertices[ face.mIndices[j] ];
                QVector3D position( pos.x, pos.y, pos.z) ;

                QVector4D color( 255.0, 165.0, 0.0, 1.0 );
                aiColor4D diffuse;
                if( AI_SUCCESS == aiGetMaterialColor(
                    mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse ) )
                {
                    color.setW( diffuse.a );
                    color.setX( diffuse.r );
                    color.setY( diffuse.g );
                    color.setZ( diffuse.b );
                }
                
                geo->setPosition( position );
                geo->setColor( color );
                geo++;
            }
        }
    }

    geo -= numVertices;

    geometry = geo;
    return true;
}

bool ModelLoader::loadTriMesh( QString filePath, btTriangleMesh*& triMesh )
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile( filePath.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );

    if( scene == NULL )
    {
        qDebug() << importer.GetErrorString();
        return false;
    }

    aiMesh* mesh = scene->mMeshes[0];

    btTriangleMesh* tempTriMesh = new btTriangleMesh();
    btVector3* triMeshVertices = new btVector3[3];

    for( unsigned int i = 0; i < mesh->mNumFaces; i++ )
    {
        const aiFace& face = mesh->mFaces[i];

        for( unsigned int j = 0; j < 3; j++ )
        {
            aiVector3D pos = mesh->mVertices[ face.mIndices[j] ];
            triMeshVertices[j] = btVector3( pos.x, pos.y, pos.z );
        }

        tempTriMesh->addTriangle( triMeshVertices[0], triMeshVertices[1], 
            triMeshVertices[2] );
    }

    triMesh = tempTriMesh;
    return true;
}

