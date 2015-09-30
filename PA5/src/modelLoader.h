#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <QString>

#include <QVector>
#include <QVector3D>
#include <QVector4D>

#include <QMatrix4x4>

#include <QSharedPointer>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct MaterialInfo
{
    QString Name;
    QVector3D Ambient;
    QVector3D Diffuse;
    QVector3D Specular;
    float Shininess;
};

struct LightInfo
{
    QVector4D Position;
    QVector3D Intensity;
};

struct Mesh
{
    QString name;
    unsigned int indexCount;
    unsigned int indexOffset;
    QSharedPointer<MaterialInfo> material;
};

struct Node
{
    QString name;
    QMatrix4x4 transformation;
    QVector< QSharedPointer<Mesh> > meshes;
    QVector<Node> nodes;
};

class ModelLoader
{
public:
    ModelLoader();
    bool Load( QString path );
    void getBufferData( QVector<float>* vertices, QVector<float>* normals,
        QVector<unsigned int>* indices );
    QSharedPointer<Node> getNodeData();

private:
    QSharedPointer<MaterialInfo> processMaterial( aiMaterial* material );
    QSharedPointer<Mesh> processMesh( aiMesh* mesh );
    void processNode( const aiScene* scene, aiNode* node, Node* parentNode,
        Node& newNode );

    void transformToUnitCoordinates();
    void findObjectDimensions( Node* node, QMatrix4x4 transformation, 
        QVector3D& minDimension, QVector3D& maxDimension );

    QVector<float> m_vertices;
    QVector<float> m_normals;
    QVector<unsigned int> m_indices;

    QVector< QSharedPointer<MaterialInfo> > m_materials;
    QVector< QSharedPointer<Mesh> > m_meshes;
    QSharedPointer<Node> m_rootNode;
};

#endif  //  MODEL_LOADER_H