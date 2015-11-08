#include "hockeyPaddle.h"


HockeyPaddle::HockeyPaddle( const QString &color )
    :   ColorPhysicsEntity( 
            btTransform( 
                btQuaternion( 0, 0, 0, 1 ), 
                [&, color]{ 
                    return color == "Red" ? btVector3( -5, 50, 0 ) : btVector3( 5, 50, 0 );
                }()
            ),
            1, 
            [&, color]{ 
                return color == "Red" ? "models/Paddle250r.obj" : "models/Paddle250b.obj";
            }()
        )
{
}