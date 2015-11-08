#include "hockeyPuck.h"

HockeyPuck::HockeyPuck()
    :   ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
        btVector3( 0, 30.5, 0 ) ), 0.5, "models/Puck150.obj" )
{
    // limit movement to x and z
    RigidBody->setLinearFactor(btVector3(1, 0, 1));

    // limit rotation to y
    RigidBody->setAngularFactor(btVector3(0, 1, 0));
}