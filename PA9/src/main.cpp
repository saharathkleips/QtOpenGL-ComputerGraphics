/** @file main.cpp
 * @mainpage PA9 Air Hockey
 * @author Ben Nicholes, Denis Morozov, Saharath Kleips
 * @version 1.00
 * @brief This project showcases a physics-based air hockey video game.
 */

#include <QApplication>
#include "UI/mainWindow.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    
    MainWindow mainWindow;
    mainWindow.resize( QSize( 800, 600 ) );
    mainWindow.setWindowTitle( "PA9 Air Hockey - Ben Nicholes, Denis Morozov, " 
        "Saharath Kleips" );
    mainWindow.show();

    return app.exec();
}