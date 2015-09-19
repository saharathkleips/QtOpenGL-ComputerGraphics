#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <QMatrix4x4>

#include <QMenu>

#include "transform3d.h"
#include "camera3d.h"

class QOpenGLShaderProgram;

class GLWidget :    public QOpenGLWidget,
                    protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget();
    ~GLWidget();

    virtual void initializeGL();
    virtual void resizeGL( int width, int height );
    virtual void paintGL();
    virtual void teardownGL();

protected slots:
    void update();
    void pause();
    void set_rotate_cw(bool cw);
    void set_rotate_cw_moon(bool cw);
    void set_translate_cw(bool cw);
    void set_translate_cw_moon(bool cw);
    void contextMenuRequested(QPoint point);

signals:
    void exitFlag();
    void rotateClockwise(bool cw);
    void rotateClockwiseMoon(bool cw);
    void translateClockwise(bool cw);
    void translateClockwiseMoon(bool cw);
    void contextMenuRequest(QPoint point);

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    //  OpenGL State Information
    QOpenGLBuffer vertex_buffer;
    QOpenGLVertexArrayObject vao;
    QOpenGLShaderProgram* program;

    //  Shader Information
    int model_to_world;
    int world_to_eye;
    int eye_to_clip;

    QMatrix4x4 projection;
    Camera3D camera3d;
    Transform3D transform3d;
    Transform3D transform3d_2;

    // Planet System Helper Variables
    bool is_paused;

    //  Cube Helper Variables
    bool rotate_cw;
    bool translate_cw;

    // Moon Helper Variables
    bool rotate_cw_moon;
    bool translate_cw_moon;

    //  Context Menu
    QMenu* context_menu;
    QAction* action_pause;
    QAction* action_exit;

    //  Orbit Label
    QString orbit_string;

    //  Private Helpers
    void printContextInformation();
    void setOrbitString();
};

#endif  //  GLWIDGET_H