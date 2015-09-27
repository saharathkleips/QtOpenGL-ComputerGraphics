#ifndef CUBE_H
#define CUBE_H

#include "renderable.h"
#include "sg_vertices.h"

class Cube  :   public Renderable
{
public:
    Cube();
    ~Cube();

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void teardownGL();
};

#endif  //  CUBE_H