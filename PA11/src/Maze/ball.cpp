#include "ball.h"

/**
 * @brief      Default constructor for Ball.
 */
Ball::Ball( const float x, const float y, const float z, bool isBoulder )
    :   UVPhysicsEntity( 
            btTransform( btQuaternion(0, 0, 0, 1), btVector3(x, y, z) ), // initial state
            1, // mass
            "models/UVSphere50.obj", 
            [isBoulder]{
				return isBoulder == true ? "textures/Sphere_Boulder.jpg" : "textures/Sphere_Snowball.jpg";
			}()
        )
{
}
