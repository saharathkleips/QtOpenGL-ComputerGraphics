#ifndef CUBE_H
#define CUBE_H

#include <QString>

#include "baseEntity.h"

class Cube  :   public BaseEntity
{
public:
    Cube();
    ~Cube();

    void update();

private:
    const QString PATH_TO_MODEL = "models/cube.obj";
};

#endif  //  CUBE_H