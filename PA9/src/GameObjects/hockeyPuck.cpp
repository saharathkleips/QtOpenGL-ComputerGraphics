#include "hockeyPuck.h"

HockeyPuck::HockeyPuck()
    :   ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
        btVector3( 0, 50, 0 ) ), 1, "models/Puck150.obj" )
{

}