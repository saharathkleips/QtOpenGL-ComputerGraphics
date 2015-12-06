/** @file main.cpp
 * @mainpage PA11 Air Hockey
 * @author Ben Nicholes, Denis Morozov, Saharath Kleips
 * @version 1.00
 * @brief This project showcases a physics-based labyrinth game.
 */

#include <QApplication>
#include <time.h>
#include "UI/mainWindow.h"

int main( int argc, char** argv )
{
    srand( 52 );

    QApplication app( argc, argv );
    
    MainWindow mainWindow;
    mainWindow.resize( QSize( 800, 600 ) );
    mainWindow.setWindowTitle( "PA11 Labyrinth - Ben Nicholes, Denis Morozov, " 
        "Saharath Kleips" );
    mainWindow.show();

    return app.exec();
}