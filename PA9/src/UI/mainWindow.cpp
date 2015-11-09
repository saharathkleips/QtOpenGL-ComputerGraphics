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

    oglWidget = new OGLWidget();
    mainMenuWidget = new MainMenuWidget();
    teamSelectWidget = new TeamSelectWidget(); 

    createActions();
    createMenus();
    createMenuBar();

    setCentralWidget( mainMenuWidget );

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
    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    oglWidget = new OGLWidget( team1, team2 );
    oglWidget->setFormat( format );

    connect( actionPauseProgram, SIGNAL( triggered() ), 
        oglWidget , SLOT( pause() ) );

    m_signalMapper = new QSignalMapper( oglWidget );
    connect( actionSideAngled, SIGNAL ( triggered() ),
        m_signalMapper, SLOT( map() ) );
    m_signalMapper->setMapping( actionSideAngled, 2 );    
    connect( actionBehindPlayer1, SIGNAL ( triggered() ),
        m_signalMapper, SLOT( map() ) );
    m_signalMapper->setMapping( actionBehindPlayer1, 0 );
    connect( actionBehindPlayer2, SIGNAL ( triggered() ),
        m_signalMapper, SLOT( map() ) );
    m_signalMapper->setMapping( actionBehindPlayer2, 1 );
        connect( actionTopDown, SIGNAL ( triggered() ),
        m_signalMapper, SLOT( map() ) );
    m_signalMapper->setMapping( actionTopDown, 3 );

    connect( m_signalMapper, SIGNAL( mapped( int ) ),
        oglWidget, SLOT( setPerspective( int ) ) );

    setCentralWidget( oglWidget );
    setMenuBar( menuBar );
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

    actionPauseProgram = new QAction( "Pause Program", this );
    actionPauseProgram->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_P ) );
    actionPauseProgram->setStatusTip( "Pauses the program." );

    actionSideAngled = new QAction( "Side Perspective", this );
    actionSideAngled->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_F3 ) );
    actionSideAngled->setStatusTip( "View the table from the side." );

    actionBehindPlayer1 = new QAction( "Player 1 Perspective", this );
    actionBehindPlayer1->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_F1 ) );
    actionBehindPlayer1->setStatusTip( "View the table from behind player 1." );

    actionBehindPlayer2 = new QAction( "Player 2 Perspective", this );
    actionBehindPlayer2->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_F2 ) );
    actionBehindPlayer2->setStatusTip( "View the table from behind player 2." );

    actionTopDown = new QAction( "Top Down Perspective", this );
    actionTopDown->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_F4 ) );
    actionTopDown->setStatusTip( "View the table from top down." );
}

/**
 * @brief      Creates the main window's menus.
 */
void MainWindow::createMenus()
{
    menuFile = new QMenu( "&File" );
    menuFile->addAction( actionPauseProgram );
    menuFile->addAction( actionExitProgram );

    menuCamera = new QMenu( "&Camera" );
    menuCamera->addAction( actionBehindPlayer1 );
    menuCamera->addAction( actionBehindPlayer2 );
    menuCamera->addAction( actionSideAngled );
    menuCamera->addAction( actionTopDown );
}

/**
 * @brief      Creates the main window's menu bar.
 */
void MainWindow::createMenuBar()
{
    menuBar = new QMenuBar();
    menuBar->addMenu( menuFile );
    menuBar->addMenu( menuCamera );
}