#ifndef OGL_WIDGET_H
#define OGL_WIDGET_H

#include <QApplication>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QMatrix4x4>

#include <QKeyEvent>

#include <QDebug>
#include <QString>

#include "camera3d.h"
#include "renderable.h"
#include "cube.h"
#include "suzanne.h"

class OGLWidget    :    public QOpenGLWidget,
                        protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget();
    OGLWidget( QString modelPath );
    ~OGLWidget();

    virtual void initializeGL();
    virtual void resizeGL( int width, int height );
    virtual void paintGL();
    virtual void teardownGL();

protected slots:
    void update();

signals:
    void exitFlag();

protected:
    void keyPressEvent( QKeyEvent* event );

private:
    void printContextInfo();

    Renderable* cube;
    Renderable* suzanne;

    QMatrix4x4 projection;
    Camera3D camera;
};

#endif  //  OGL_WIDGET_H