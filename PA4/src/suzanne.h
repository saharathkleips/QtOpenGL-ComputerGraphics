#ifndef SUZANNE_H
#define SUZANNE_H

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

class Suzanne   :   public Renderable
{
public:
    Suzanne();
    Suzanne( QString path );
    ~Suzanne();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void teardownGL();

private:
    Vertex* loadObj( QString path );

    Vertex* model;
    int numVertices;
};

#endif  //  SUZANNE_H