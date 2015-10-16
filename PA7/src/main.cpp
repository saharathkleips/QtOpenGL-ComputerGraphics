#include <QApplication>
#include "mainWindow.h"
#include "oglWidget.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    
    MainWindow mainWindow;
    mainWindow.resize( QSize( 800, 600 ) );
    mainWindow.show();

    return app.exec();
}