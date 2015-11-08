#include "hockeyPaddle.h"


HockeyPaddle::HockeyPaddle( const QString &color ) : ColorPhysicsEntity( 
    btTransform( 
        btQuaternion( 0, 0, 0, 1 ), 
        [&, color]{ 
            return color == "Red" ? btVector3( -25, 30.5f, 0 ) : btVector3( 25, 30.5f, 0 );
        }()
    ),
    1, 
    [&, color]{ 
        return color == "Red" ? "models/Paddle250r.obj" : "models/Paddle250b.obj";
    }()
)

{
    RigidBody->setLinearFactor(btVector3(1, 0, 1));
}