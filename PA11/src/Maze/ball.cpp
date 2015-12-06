#include "ball.h"

/**
 * @brief      Default constructor for Ball.
 */
Ball::Ball()
    :   UVPhysicsEntity( 
            btTransform( btQuaternion(0, 0, 0, 1), btVector3(2, 5, 9.5f) ), // initial state
            1, // mass
            "models/UVSphere.obj", 
            "textures/Sphere_Boulder.jpg"
        )
{
    // limit movement to x and z
    //RigidBody->setLinearFactor(btVector3(1, 0, 1));

    // limit rotation to y
    //RigidBody->setAngularFactor(btVector3(0, 1, 0));
}
