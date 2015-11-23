#include "mainWindow.h"

//
// CONSTRUCTOR /////////////////////////////////////////////////////////////////
//

/**
 * @brief     Main window for OpenGL based projects.
 * @details   Creates an OGLWidget with an OpenGL surface to draw on as the
 * central widget. A menu bar will also be created for user interaction with the
 * central widget.
 */
MainWindow::MainWindow()
{
    setMinimumSize( 800, 600 );
    oglWidget = NULL;

    restartGame();

    createActions();
    createMenus();
    createMenuBar();

    setMenuBar( menuBar );
    menuBar->show();
}

//
// PUBILC SLOTS ////////////////////////////////////////////////////////////////
//

/**
 * @brief      Slot to restart the entire game.
 */
void MainWindow::restartGame()
{

    if( oglWidget != NULL )
        delete oglWidget;

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );
    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );

    setCentralWidget( oglWidget );
}

//
// PRIVATE HELPER FUNCTIONS ////////////////////////////////////////////////////
//

/**
 * @brief      Creates the main window's actions.
 */
void MainWindow::createActions()
{
    actionExitProgram = new QAction( "Exit Program", this );
    actionExitProgram->setShortcuts( QKeySequence::Quit );
    actionExitProgram->setStatusTip( "Exits the program." );
    connect( actionExitProgram, SIGNAL( triggered() ), 
        QApplication::instance(), SLOT( quit() ) );

    actionRestartGame = new QAction( "Restart Game", this );
    actionRestartGame->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_R ) );
    actionRestartGame->setStatusTip( "Restarts the game." );
    connect( actionRestartGame, SIGNAL( triggered() ), 
        this, SLOT( restartGame() ) );
}

/**
 * @brief      Creates the main window's menus.
 */
void MainWindow::createMenus()
{
    menuFile = new QMenu( "&File" );
    menuFile->addAction( actionRestartGame );
    menuFile->addAction( actionExitProgram );
}

/**
 * @brief      Creates the main window's menu bar.
 */
void MainWindow::createMenuBar()
{
    menuBar = new QMenuBar();
    menuBar->addMenu( menuFile );
}