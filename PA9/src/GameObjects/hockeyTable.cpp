#include "hockeyTable.h"

HockeyTable::HockeyTable()
	:	ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
		btVector3( 0, 0, 0 ) ), 0, "models/HockeyTable.obj" )
{
}