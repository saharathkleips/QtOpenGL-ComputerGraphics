#ifndef CAPSULE_H
#define CAPSULE_H

#include <QApplication>

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

#include <QVector3D>
#include <QVector2D>
#include <QVector>

#include "renderable.h"
#include "vertex.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Capsule   :   public Renderable
{
public:
    Capsule();
    Capsule( QString path );
    ~Capsule();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void teardownGL();

private:
    Vertex* loadObj( QString path );

    // Model Information
    Vertex* model;
    int numVertices;

    // Texture Information
    QOpenGLTexture* texture;
};

#endif  //  CAPSULE_H