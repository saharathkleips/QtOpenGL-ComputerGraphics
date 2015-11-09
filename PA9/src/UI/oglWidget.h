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
    void initializeBullet();
    void teardownBullet();
    void flyThroughCamera();
    void controlObject();
    void printContextInfo();

    // OpenGL Objects
    QMap<QString, Renderable*> renderables;

    // 3D data
    QMatrix4x4 projection;
    Camera3D camera;

    // Bullet data
    btBroadphaseInterface* m_broadphase;
    btDefaultCollisionConfiguration* m_collisionConfig;
    btCollisionDispatcher* m_dispatcher;
    btSequentialImpulseConstraintSolver* m_solver;
    btDiscreteDynamicsWorld* m_dynamicsWorld;

    // Collision information
    const short COL_NOTHING = 0;
    const short COL_TABLE = 1 << 0;
    const short COL_PUCK = 1 << 1;
    const short COL_PADDLE = 1 << 2;
    const short m_TableCollidesWith = (COL_PUCK | COL_PADDLE);
    const short m_PuckCollidesWith = (COL_TABLE | COL_PADDLE);
    const short m_PaddleCollidesWith = (COL_TABLE | COL_PUCK);
};

#endif  //  OGL_WIDGET_H