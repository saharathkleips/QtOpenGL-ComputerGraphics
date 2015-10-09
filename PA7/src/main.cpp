#include <QApplication>
#include "oglWidget.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    // Set the drawing format
    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    // Create the main OpenGL program
    OGLWidget* oglWidget;
    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );
    oglWidget->resize( QSize( 800, 600 ) );
    oglWidget->show(); 

    return app.exec();
}