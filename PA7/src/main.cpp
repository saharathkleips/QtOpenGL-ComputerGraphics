#include <QApplication>
#include "oglWidget.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    OGLWidget* oglWidget;

    oglWidget = new OGLWidget();

    oglWidget->setFormat( format );
    oglWidget->resize( QSize( 800, 600 ) );
    oglWidget->show(); 

    return app.exec();
}