#ifndef SG_VERTICES_H
#define SG_VERTICES_H

#include "vertex.h"

static const Vertex sg_vertices[] = {
    // Front Face
    Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f,  0.5f), QVector3D( 0.0f, 1.0f, 0.0f ) ), 
        Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) ),
    Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) ),
    // Back Face
    Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 0.0f ) ),
    Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) ),
    // Top Face
    Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 0.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ),
    Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f,  0.5f), QVector3D( 0.0f, 1.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) ),
    // Bottom Face
    Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) ),
    Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) ),
    // Left Face
    Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f,  0.5f), QVector3D( 0.0f, 1.0f, 0.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ),
    Vertex( QVector3D(-0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f,  0.5f, -0.5f), QVector3D( 0.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D(-0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 0.0f, 1.0f ) ),
    // Right Face
    Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f,  0.5f), QVector3D( 0.0f, 0.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) ),
    Vertex( QVector3D( 0.5f, -0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 1.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f, -0.5f), QVector3D( 1.0f, 1.0f, 0.0f ) ), 
        Vertex( QVector3D( 0.5f,  0.5f,  0.5f), QVector3D( 1.0f, 0.0f, 0.0f ) )
};

#endif