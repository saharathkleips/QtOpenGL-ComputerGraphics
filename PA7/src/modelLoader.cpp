#include "modelLoader.h"

/**
 * @brief       Loads a model based on a file path.
 *
 * @param[in]   filePath      The full path to the model source.
 * @param[out]  geometry      The geometry data of the model loaded.
 * @param[out]  numVertices   The number of vertices within the model.
 *
 * @return     True of the model loaded successfully, false otherwise.
 */
bool ModelLoader::loadModel( QString filePath, Vertex& geometry, 
    int& numVertices )
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

    numVertices = mesh->mNumFaces * 3;
    Vertex* geo = new Vertex[ numVertices ];

    for( unsigned int i = 0; i < mesh->mNumFaces; i++ )
    {
        const aiFace& face = mesh->mFaces[i];

        for( unsigned int j = 0; j < 3; j++ )
        {
            aiVector3D pos = mesh->mVertices[ face.mIndices[j] ];
            QVector3D position( pos.x, pos.y, pos.z) ;

            aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
            QVector2D uv_coords( uv.x, uv.y );
            
            geo->setPosition( position );
            geo->setUV( uv_coords );
            
            geo++;
        }
    }

    geo -= mesh->mNumFaces * 3;

    geometry = *geo;
    return true;
}