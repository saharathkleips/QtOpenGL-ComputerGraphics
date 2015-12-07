#include "ball.h"

/**
 * @brief      Default constructor for Ball.
 */
Ball::Ball()
    :   UVPhysicsEntity( 
            btTransform( btQuaternion(0, 0, 0, 1), btVector3(2, 5, 10.0f) ), // initial state
            1, // mass
            "models/UVSphere50.obj", 
            "textures/Sphere_Boulder.jpg"
        )
{
    // TODO: uncomment this when we figure out how to place the ball
    // limit movement to x and z
    // RigidBody->setLinearFactor(btVector3(1, 0, 1));

    // limit rotation to y
    // RigidBody->setAngularFactor(btVector3(0, 1, 0));
}
