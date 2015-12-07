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
    showMaximized();

    titleWidget = NULL;
    oglWidget = NULL;
    winWidget = NULL;

    createActions();
    createMenus();
    createMenuBar();

    setMenuBar( menuBar );

    swapToTitle();
}

//
// PUBILC SLOTS ////////////////////////////////////////////////////////////////
//

void MainWindow::swapToTitle()
{
    menuBar->hide();

    titleWidget = new TitleWidget();

    connect( titleWidget, SIGNAL( clickedPlay() ), this, SLOT( swapToGame() ) );
    connect( titleWidget, SIGNAL( clickedExit() ), QApplication::instance(),
        SLOT( quit() ) );

    setCentralWidget( titleWidget );
    if( oglWidget != NULL ){
        delete oglWidget;
        oglWidget = NULL;
    }
    if( winWidget != NULL ){
        delete winWidget;
        winWidget = NULL;
    }
}

void MainWindow::swapToGame()
{
    menuBar->show();

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );
    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );

    connect( actionPauseProgram, SIGNAL(triggered()), oglWidget , SLOT(pause()) );
    connect( oglWidget, SIGNAL(win()), this, SLOT(swapToWin()));

    setCentralWidget( oglWidget );
    if( titleWidget != NULL ){
        delete titleWidget;
        titleWidget = NULL;
    }
    if( winWidget != NULL ){
        delete winWidget;
        winWidget = NULL;
    }
}

void MainWindow::swapToWin()
{
    winWidget = new WinWidget();
    setCentralWidget( winWidget );
    if( titleWidget != NULL ){
        delete titleWidget;
        titleWidget = NULL;
    }
    if( oglWidget != NULL ){
        delete oglWidget;
        oglWidget = NULL;
    }
}

/**
 * @brief      Slot to restart the entire game.
 */
void MainWindow::restartGame()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
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

    actionPauseProgram = new QAction( "Pause Program", this );
    actionPauseProgram->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_P ) );
    actionPauseProgram->setStatusTip( "Pauses the program." );

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
    menuFile->addAction( actionPauseProgram );
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