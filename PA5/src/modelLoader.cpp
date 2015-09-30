#include "modelLoader.h"

ModelLoader::ModelLoader()
{

}

bool ModelLoader::Load( QString path )
{
    Assimp::Importer importer;

    qDebug() << "Before importer.ReadFile";

    const aiScene* scene = importer.ReadFile( path.toStdString(), 
        aiProcess_GenSmoothNormals |
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType );

    qDebug() << "After importer.ReadFile";

    if( !scene )
    {
        qDebug() << "Error loading file. Assimp: " << importer.GetErrorString();
        return false;
    }

    qDebug() << "After !scene";
    
    if( scene->HasMaterials() )
    {
        for( unsigned int ii = 0; ii < scene->mNumMaterials; ++ii)
        {
            QSharedPointer<MaterialInfo> t_material = processMaterial( 
                scene->mMaterials[ii] );
            m_materials.push_back( t_material );
        }
    }

    qDebug() << "After scene->HasMaterials";

    if( scene->HasMeshes() )
    {
        for( unsigned int ii = 0; ii < scene->mNumMeshes; ++ii )
            m_meshes.push_back( processMesh( scene->mMeshes[ii] ) );
    }
    else
    {
        qDebug() << "Error: No meshes found.";
        return false;
    }

    qDebug() << "After scene->HasMeshes";

    if( scene->mRootNode != NULL )
    {
        Node* rootNode = new Node;
        processNode( scene, scene->mRootNode, 0, *rootNode );
        m_rootNode.reset( rootNode );
    }
    else
    {
        qDebug() << "Error: Model loading.";
        return false;
    }

    return true;
}

void ModelLoader::getBufferData( QVector<float>* vertices, 
    QVector<float>* normals, QVector<unsigned int>* indices )
{
    vertices = &m_vertices;
    normals = &m_normals;
    indices = &m_indices;
}

QSharedPointer<Node> ModelLoader::getNodeData()
{
    return m_rootNode;
}

QSharedPointer<MaterialInfo> ModelLoader::processMaterial( 
    aiMaterial *material )
{
    QSharedPointer<MaterialInfo> t_material( new MaterialInfo );

    aiString m_name;
    material->Get( AI_MATKEY_NAME, m_name );
    if( m_name.length > 0 )
        t_material->Name = m_name.C_Str();

    int shadingModel;
    material->Get( AI_MATKEY_SHADING_MODEL, shadingModel );

    if( shadingModel != aiShadingMode_Phong && 
        shadingModel != aiShadingMode_Gouraud)
    {
        qDebug() << "Shading model mesh not implemented in this loader." << 
            "default material.";
        t_material->Name = "DefaultMaterial";
    }
    else
    {
        aiColor3D dif( 0.0f, 0.0f, 0.0f );
        aiColor3D amb( 0.0f, 0.0f, 0.0f );
        aiColor3D spec( 0.0f, 0.0f, 0.0f );
        float shine = 0.0;

        material->Get( AI_MATKEY_COLOR_AMBIENT, amb );
        material->Get( AI_MATKEY_COLOR_DIFFUSE, dif );
        material->Get( AI_MATKEY_COLOR_SPECULAR, spec );
        material->Get( AI_MATKEY_SHININESS, shine );

        t_material->Ambient = QVector3D( amb.r, amb.g, amb.b );
        t_material->Diffuse = QVector3D( dif.r, dif.g, dif.b );
        t_material->Specular = QVector3D( spec.r, spec.g, spec.b );
        t_material->Shininess = shine;

        t_material->Ambient *= .2;
        if( t_material->Shininess == 0.0f )
            t_material->Shininess = 30;
    }

    return t_material;
}

QSharedPointer<Mesh> ModelLoader::processMesh( aiMesh* mesh )
{
    QSharedPointer<Mesh> newMesh( new Mesh );
    newMesh->name = mesh->mName.length != 0 ? mesh->mName.C_Str() : "";
    newMesh->indexOffset = m_indices.size();
    unsigned int indexCountBefore = m_indices.size();
    int vertexIndexOffset = m_vertices.size() / 3;

    qDebug() << "After processMesh variables";

    // Get Vertices
    if( mesh->mNumVertices > 0 )
    {
        for( uint ii = 0; ii < mesh->mNumVertices; ++ii )
        {
            aiVector3D& vec = mesh->mVertices[ii];

            m_vertices.push_back( vec.x );
            m_vertices.push_back( vec.y );
            m_vertices.push_back( vec.z );
        }
    }

    qDebug() << "After get vertices";

    // Get Normals
    if( mesh->HasNormals() )
    {
        for( uint ii = 0; ii < mesh->mNumVertices; ++ii )
        {
            aiVector3D& vec = mesh->mNormals[ii];

            m_normals.push_back( vec.x );
            m_normals.push_back( vec.y );
            m_normals.push_back( vec.z );
        }
    }

    qDebug() << "After get normals";

    // Get Mesh Indexes
    for( uint t = 0; t < mesh->mNumFaces; ++t )
    {
        aiFace* face = &mesh->mFaces[t];
        qDebug() << "After aiFace definition";

        if( face->mNumIndices != 3 )
        {
            qDebug() << "Warning: Mesh face does not contain exactly 3" <<
                "indices. This primitive will be ignored.";
        }

        qDebug() << "Before first indices push_back";
        m_indices.push_back( face->mIndices[0] + vertexIndexOffset );
        qDebug() << "After first indices push_back";
        m_indices.push_back( face->mIndices[1] + vertexIndexOffset );
        m_indices.push_back( face->mIndices[2] + vertexIndexOffset );
    }

    qDebug() << "After get Mesh Indexes";

    newMesh->indexCount = m_indices.size() - indexCountBefore;
    newMesh->material = m_materials.at( mesh->mMaterialIndex );

    return newMesh;
}

void ModelLoader::processNode( const aiScene *scene, aiNode *node,
    Node* parentNode, Node& newNode)
{
    newNode.name = node->mName.length != 0 ? node->mName.C_Str() : "";

    newNode.transformation = QMatrix4x4( node->mTransformation[0] );
    
    newNode.meshes.resize( node->mNumMeshes );
    for( uint iMesh = 0; iMesh < node->mNumMeshes; ++iMesh )
    {
        QSharedPointer<Mesh> mesh = m_meshes[node->mMeshes[iMesh]];
        newNode.meshes[iMesh] = mesh;
    }

    for( uint ich = 0; ich < node->mNumChildren; ++ich )
    {
        newNode.nodes.push_back( Node() );
        processNode( scene, node->mChildren[ich], parentNode, 
            newNode.nodes[ich]);
    }
}