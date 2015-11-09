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
    // Load Fonts
    QFontDatabase::addApplicationFont( ":/fonts/NHL.ttf" );

    setMinimumSize( 800, 600 );

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );

    mainMenuWidget = new MainMenuWidget();

    teamSelectWidget = new TeamSelectWidget(); 

    createActions();
    createMenus();
    createMenuBar();

    setCentralWidget( mainMenuWidget );
    setMenuBar( menuBar );

    connect( mainMenuWidget, SIGNAL( clickedSinglePlayer() ), 
        this, SLOT( swapToTeamSelect() ) );
    connect( mainMenuWidget, SIGNAL( clickedTwoPlayer() ), 
        this, SLOT( swapToTeamSelect() ) );
    connect( mainMenuWidget, SIGNAL( clickedExit() ), 
        QApplication::instance(), SLOT( quit() ) );
    connect( teamSelectWidget, SIGNAL( selectedTeams( QString, QString ) ),
        this, SLOT( swapToGame( QString, QString ) ) );
}

//
// PUBILC SLOTS ////////////////////////////////////////////////////////////////
//
void MainWindow::swapToTeamSelect()
{
    setCentralWidget( teamSelectWidget );
    if( mainMenuWidget != NULL )
    {
        delete mainMenuWidget;
        mainMenuWidget = NULL;
    }
}

void MainWindow::swapToGame( QString team1, QString team2 )
{
    qDebug() << team1 << team2;
    setCentralWidget( oglWidget );
    if( teamSelectWidget != NULL )
    {
        delete teamSelectWidget;
        teamSelectWidget = NULL;
    }
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
}

/**
 * @brief      Creates the main window's menus.
 */
void MainWindow::createMenus()
{
    menuFile = new QMenu( "&File" );
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