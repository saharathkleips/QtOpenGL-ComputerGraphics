#include "hockeyPaddle.h"


HockeyPaddle::HockeyPaddle( const QString &color ) : ColorPhysicsEntity( 
    // initial position and rotation
    btTransform( 
        btQuaternion( 0, 0, 0, 1 ), 
        [&, color]{ 
            return color == "Red" ? btVector3( -25, 30.5f, 0 ) : btVector3( 25, 30.5f, 0 );
        }()
    ),
    // mass
    5,
    // path to model 
    [&, color]{ 
        return color == "Red" ? "models/Paddle250r.obj" : "models/Paddle250b.obj";
    }()
)

{
    // limit movement to x and z
    RigidBody->setLinearFactor(btVector3(1, 0, 1));

    // limit rotation to y
    RigidBody->setAngularFactor(btVector3(0, 1, 0));
}