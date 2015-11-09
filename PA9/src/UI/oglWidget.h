#ifndef OGL_WIDGET_H
#define OGL_WIDGET_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QPainter>
#include <QFont>
#include <QRect>
#include <QFontDatabase>
#include <QLabel>
#include <QPixmap>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QMap>
#include <QMatrix4x4>
#include <QMediaPlayer>
#include <QFileInfo>

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

class OGLWidget    :    public QOpenGLWidget,
                        protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget();
    OGLWidget( QString team1, QString team2 );
    ~OGLWidget();

    virtual void initializeGL();
    virtual void resizeGL( int width, int height );
    virtual void paintGL();
    virtual void teardownGL();

public slots:
    void setPerspective( int perspective );

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
        GoalCallback(OGLWidget* scopePtr) : context(scopePtr)
        {            
        }

        btScalar addSingleResult(btManifoldPoint& cp,
            const btCollisionObjectWrapper* colObj0Wrap,
            int partId0,
            int index0,
            const btCollisionObjectWrapper* colObj1Wrap,
            int partId1,
            int index1)
        {
            // silence unused variable noise
            (void)partId0;(void)partId1;(void)index0;(void)index1;(void)colObj0Wrap;(void)colObj1Wrap;(void)cp;
            context->processGoal();
            context->m_p1Score++;
            // return doesn't actually do anything
            return 1.0f;
        }

        OGLWidget* context;
    };

    struct Goal2Callback : public btCollisionWorld::ContactResultCallback
    {
        Goal2Callback(OGLWidget* scopePtr) : context(scopePtr)
        {            
        }

        btScalar addSingleResult(btManifoldPoint& cp,
            const btCollisionObjectWrapper* colObj0Wrap,
            int partId0,
            int index0,
            const btCollisionObjectWrapper* colObj1Wrap,
            int partId1,
            int index1)
        {
            // silence unused variable noise
            (void)partId0;(void)partId1;(void)index0;(void)index1;(void)colObj0Wrap;(void)colObj1Wrap;(void)cp;
            context->processGoal();
            context->m_p2Score++;
            // return doesn't actually do anything
            return 1.0f;
        }

        OGLWidget* context;
    };

       struct PuckCallback : public btCollisionWorld::ContactResultCallback
    {
        PuckCallback(OGLWidget* scopePtr) : context(scopePtr)
        {            
        }

        btScalar addSingleResult(btManifoldPoint& cp,
            const btCollisionObjectWrapper* colObj0Wrap,
            int partId0,
            int index0,
            const btCollisionObjectWrapper* colObj1Wrap,
            int partId1,
            int index1)
        {
            (void)partId0;(void)partId1;(void)index0;(void)index1;(void)colObj0Wrap;(void)colObj1Wrap;(void)cp;
            context->puckContactSound();
            return 1.0f;
        }

        OGLWidget* context;
    };
    

    void initializeBullet();
    void teardownBullet();
    void flyThroughCamera();
    void controlObject();
    void printContextInfo();
    void processGoal();
    void puckContactSound();


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

    // media player
    QMediaPlayer *player;

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

    QString m_pathToTeam1 = "images/Team Logos/Avalanches.png";
    QString m_pathToTeam2 = "images/Team Logos/Blackhawks.png";
    QPixmap *m_imgTeam1, *m_imgTeam2;
    QLabel *m_p1Team, *m_p2Team;
    int m_p1Score, m_p2Score;
};

#endif  //  OGL_WIDGET_H