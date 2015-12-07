#include "ball.h"

/**
 * @brief      Default constructor for Ball.
 */
Ball::Ball( const float x, const float y, const float z )
    :   UVPhysicsEntity( 
            btTransform( btQuaternion(0, 0, 0, 1), btVector3(x, y, z) ), // initial state
            1, // mass
            "models/UVSphere50.obj", 
            "textures/Sphere_Boulder.jpg"
        )
{
}
