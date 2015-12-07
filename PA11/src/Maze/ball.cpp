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
    // limit movement to x and z
    RigidBody->setLinearFactor(btVector3(1, 0, 1));

    // limit rotation to y
    RigidBody->setAngularFactor(btVector3(0, 1, 0));
}
