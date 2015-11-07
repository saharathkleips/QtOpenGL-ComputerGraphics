#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <QString>
#include <QDebug>

#include "uvVertex.h"
#include "colorVertex.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <btBulletDynamicsCommon.h>

namespace ModelLoader
{
    bool loadUVModel( QString filePath, UVVertex*& geometry, int& numVertices );
    bool loadColorModel( QString filePath, ColorVertex*& geometry, 
        int& numVertices );
    bool loadTriMesh( QString filePath, btTriangleMesh*& collisionMesh );
};

#endif  //  MODEL_LOADER_H