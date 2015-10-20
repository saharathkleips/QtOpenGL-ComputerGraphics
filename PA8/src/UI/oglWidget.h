#ifndef OGL_WIDGET_H
#define OGL_WIDGET_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QMap>
#include <QMatrix4x4>

#include <QDebug>
#include <QString>

#include "Controls/input.h"
#include "Controls/camera3d.h"
#include "3D/renderable.h"
#include "Entity/cube.h"
#include "Entity/cylindar.h"
#include "Entity/sphere.h"

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
    void flyThroughCamera();
    void printContextInfo();

    // 3D Information
    QMap<QString, Renderable*> renderables;

    QMatrix4x4 projection;
    Camera3D camera;
};

#endif  //  OGL_WIDGET_H