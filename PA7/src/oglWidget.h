#ifndef OGL_WIDGET_H
#define OGL_WIDGET_H

#include <QApplication>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QVector>
#include <QVectorIterator>
#include <QMatrix4x4>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QDebug>
#include <QString>

#include "input.h"
#include "camera3d.h"
#include "renderable.h"
#include "Planets/sun.h"

class OGLWidget    :    public QOpenGLWidget,
                        protected QOpenGLFunctions
{
    Q_OBJECT

public:
    OGLWidget();
    OGLWidget( QString modelPath, QString texturePath );
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
    void printContextInfo();

    // 3D Information
    QVector<Renderable*> renderables;

    QMatrix4x4 projection;
    Camera3D camera;
};

#endif  //  OGL_WIDGET_H