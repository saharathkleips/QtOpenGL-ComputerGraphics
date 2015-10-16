#include "mainWindow.h"

MainWindow::MainWindow()
{
    createActions();
    createMenus();
    createMenuBar();

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );

    setCentralWidget( oglWidget );
    setMenuBar( menuBar );
}

void MainWindow::createActions()
{
    exitAction = new QAction( "Exit", this );
    exitAction->setShortcuts( QKeySequence::Quit );
    exitAction->setStatusTip( "Exits the program." );
    connect( exitAction, SIGNAL( triggered() ), 
        QApplication::instance(), SLOT( quit() ) );
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu( "&File" );
    fileMenu->addAction( exitAction );
}

void MainWindow::createMenuBar()
{
    menuBar = new QMenuBar( );
    menuBar->addMenu( fileMenu );
}