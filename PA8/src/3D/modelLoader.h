#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <QString>
#include <QDebug>

#include "vertex.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace ModelLoader
{
    bool loadModel( QString filePath, Vertex*& geometry, 
        int& numVertices );
};

#endif  //  MODEL_LOADER_H