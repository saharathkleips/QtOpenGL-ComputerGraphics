#ifndef OGL_WIDGET_H
#define OGL_WIDGET_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QPainter>
#include <QFont>
#include <QRect>
#include <QFontDatabase>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QMap>
#include <QMatrix4x4>

#include <QDebug>
#include <QString>

#include <btBulletDynamicsCommon.h>

#include "Controls/input.h"
#include "Controls/camera3d.h"
#include "3D/renderable.h"
#include "GameObjects/hockeyTable.h"
#include "GameObjects/hockeyPuck.h"
#include "GameObjects/hockeyPaddle.h"
#include "GameObjects/skybox.h"
#include "GameObjects/wall.h"

#include <iostream>

class OGLWidget    :    public QOpenGLWidget,
                        protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget();
    ~OGLWidget();

    virtual void initializeGL();
    virtual void resizeGL( int width, int height );
    virtual void paintGL();
    virtual void teardownGL();

protected slots:
    void update();

protected:
    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent( QKeyEvent* event );
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );

private:
    struct GoalCallback : public btCollisionWorld::ContactResultCallback
    {
        btScalar addSingleResult(btManifoldPoint& cp,
            const btCollisionObjectWrapper* colObj0Wrap,
            int partId0,
            int index0,
            const btCollisionObjectWrapper* colObj1Wrap,
            int partId1,
            int index1)
        {
            // your callback code here
            std::cout << "GOAL RED" << std::endl;
        }
    };

    struct Goal2Callback : public btCollisionWorld::ContactResultCallback
    {
        btScalar addSingleResult(btManifoldPoint& cp,
            const btCollisionObjectWrapper* colObj0Wrap,
            int partId0,
            int index0,
            const btCollisionObjectWrapper* colObj1Wrap,
            int partId1,
            int index1)
        {
            std::cout << "GOAL BLUE" << std::endl;
        }
    };

    GoalCallback goalCallback;
    Goal2Callback goal2Callback;
    

    void initializeBullet();
    void teardownBullet();
    void flyThroughCamera();
    void controlObject();
    void printContextInfo();

    // OpenGL Objects
    QMap<QString, Renderable*> renderables;

    // Invisible walls for collisions
    QMap<QString, Wall*> walls;

    // 3D data
    QMatrix4x4 projection;
    Camera3D camera;

    // Bullet data
    btBroadphaseInterface* m_broadphase;
    btDefaultCollisionConfiguration* m_collisionConfig;
    btCollisionDispatcher* m_dispatcher;
    btSequentialImpulseConstraintSolver* m_solver;
    btDiscreteDynamicsWorld* m_dynamicsWorld;

    /* Collision information */
    const short COL_NOTHING = 0;
    // Renderables
    const short COL_TABLE = 1 << 0;
    const short COL_PUCK = 1 << 1;
    const short COL_PADDLE = 1 << 2;
    // Walls
    const short COL_MIDDLE = 1 << 3;
    const short COL_GOAL = 1 << 4;

    // Renderables
    const short m_TableCollidesWith = ( COL_PUCK | COL_PADDLE );
    const short m_PuckCollidesWith = ( COL_TABLE | COL_PADDLE | COL_GOAL );
    const short m_PaddleCollidesWith = ( COL_TABLE | COL_PUCK | COL_MIDDLE ); 
    // Walls
    const short m_MiddleCollidesWith = COL_PADDLE;
    const short m_GoalCollidesWith = (COL_PUCK);

};

#endif  //  OGL_WIDGET_H