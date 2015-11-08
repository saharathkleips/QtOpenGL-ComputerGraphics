#include "hockeyPuck.h"

HockeyPuck::HockeyPuck()
    :   ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
        btVector3( 0, 30.5, 0 ) ), 1, "models/Puck150.obj" )
{
    RigidBody->setLinearFactor(btVector3(1, 0, 1));
}