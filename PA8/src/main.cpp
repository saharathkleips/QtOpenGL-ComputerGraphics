#include <QApplication>
#include "UI/mainWindow.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    
    MainWindow mainWindow;
    mainWindow.resize( QSize( 800, 600 ) );
    mainWindow.setWindowTitle( "PA8 Bullet - Ben Nicholes, Denis Morozov, " 
        "Saharath Kleips" );
    mainWindow.show();

    return app.exec();
}