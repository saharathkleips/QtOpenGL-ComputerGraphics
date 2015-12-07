#ifndef BALL_H
#define BALL_H

#include "Entity/uvPhysicsEntity.h"

class Ball    :   public UVPhysicsEntity
{
public:
    Ball( const float x = 2.0f, const float y = 5.0f, const float z = 10.0f, bool isBoulder = true );
};

#endif  //  BALL_H