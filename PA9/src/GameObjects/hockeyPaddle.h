#ifndef HOCKEY_PADDLE_H
#define HOCKEY_PADDLE_H

#include "Entity/colorPhysicsEntity.h"

class HockeyPaddle   :   public ColorPhysicsEntity
{
public:
    HockeyPaddle( const QString &color );
};

#endif  //  HOCKEY_PADDLE_H