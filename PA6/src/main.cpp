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

    if( argc == 1 )
        oglWidget = new OGLWidget();
    else if( argc == 3 )
        oglWidget = new OGLWidget( argv[1], argv[2] );
    else
    {
        qDebug() << "To load a custom model please provide the " <<
            "/path/to/model followed by the /path/to/texture";
        qDebug() << "Example: ./PA6.exe models/capsule.obj " <<
            "../build/textures/capsule.jpg";
        return EXIT_FAILURE;
    }

    oglWidget->setFormat( format );
    oglWidget->resize( QSize( 800, 600 ) );
    oglWidget->show(); 

    return app.exec();
}