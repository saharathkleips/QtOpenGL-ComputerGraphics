#ifndef CELL_H
#define CELL_H

#include <QMatrix4x4>
#include <QString>

#include "Entity/uvPhysicsEntity.h"
#include "Controls/camera3d.h"

class Cell  :   public UVPhysicsEntity
{
public:
    Cell( btTransform startingState, QString pathToTexture );

    void initializeGL();
    void paintGL( Camera3D& camera, QMatrix4x4& projection );
    void update();
    void teardownGL();
};

#endif  //  CELL_H