#include <QApplication>
#include "glWidget.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //Set OpenGL Version Information
    // QSurfaceFormat format;
    // format.setRenderableType(QSurfaceFormat::OpenGL);
    // format.setProfile(QSurfaceFormat::CoreProfile);
    // format.setVersion(3,3);

    //Create The OpenGL Window
    // Window window;
    // window.setFormat(format);
    // window.resize(QSize(800, 600));
    // window.show();

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    //  Create OpenGLWidget
    GLWidget glwidget;
    glwidget.setFormat( format );
    glwidget.resize( QSize( 800, 600 ) );
    glwidget.show();

    return app.exec();
}