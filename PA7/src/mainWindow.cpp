#include "mainWindow.h"

MainWindow::MainWindow()
{
    webWidget = new QWidget();
    webWidget->setFixedHeight( 600 );
    webWidget->setFixedWidth( 800 );
    webview = new QWebView( webWidget );
    webview->setFixedHeight( 600 );
    webview->setFixedWidth( 800 );

    QSurfaceFormat format;
    format.setDepthBufferSize( 24 );
    format.setSwapBehavior( QSurfaceFormat::DoubleBuffer );
    format.setRenderableType( QSurfaceFormat::OpenGL );
    format.setProfile( QSurfaceFormat::NoProfile );
    format.setVersion( 2,1 );

    oglWidget = new OGLWidget();
    oglWidget->setFormat( format );

    createActions();
    createMenus();
    createMenuBar();

    setCentralWidget( oglWidget );
    setMenuBar( menuBar );

}

void MainWindow::createActions()
{
    pauseAction = new QAction( "Start Simulation", this );
    pauseAction->setCheckable( true );
    pauseAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_P ) );
    pauseAction->setStatusTip( "Pauses / Unpauses the Simulation." );
    connect( pauseAction, SIGNAL( triggered() ), 
        oglWidget, SLOT( swapPause() ) );
    
    scaledAction = new QAction( "Realistic View", this );
    scaledAction->setCheckable( true );
    scaledAction->setChecked( true );
    scaledAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_R ) );
    scaledAction->setStatusTip( "Swaps the scale of the solar system." );
    connect( scaledAction, SIGNAL( triggered() ), 
        oglWidget, SLOT( swapScaledView() ) );

    exitAction = new QAction( "Exit", this );
    exitAction->setShortcuts( QKeySequence::Quit );
    exitAction->setStatusTip( "Exits the program." );
    connect( exitAction, SIGNAL( triggered() ), 
        QApplication::instance(), SLOT( quit() ) );

    aboutAction = new QAction( "About", this );
    aboutAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_A  ) );
    aboutAction->setStatusTip( "Details about the program." );
    connect( aboutAction, SIGNAL( triggered() ), 
        this, SLOT( showAbout() ) );

    aboutQtAction = new QAction( "About Qt", this );
    aboutQtAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_T  ) );
    aboutQtAction->setStatusTip( "Details about the Qt Framework." );
    connect( aboutQtAction, SIGNAL( triggered() ), 
        this, SLOT( showAboutQt() ) );

    controlsAction = new QAction( "Controls", this );
    controlsAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_C  ) );
    controlsAction->setStatusTip( "Details about controlling the program." );
    connect( controlsAction, SIGNAL( triggered() ), 
        this, SLOT( showControls() ) );

    moreHelpAction = new QAction( "More Help?", this );
    moreHelpAction->setShortcut( QKeySequence( Qt::CTRL + Qt::Key_H  ) );
    moreHelpAction->setStatusTip( "You need more help." );
    connect( moreHelpAction, SIGNAL( triggered() ), 
        this, SLOT( showLmgtfy() ) );
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu( "&File" );
    fileMenu->addAction( pauseAction );
    fileMenu->addAction( scaledAction );
    fileMenu->addAction( exitAction );
    helpMenu = new QMenu( "&Help" );
    helpMenu->addAction( aboutAction );
    helpMenu->addAction( controlsAction );
    helpMenu->addAction( moreHelpAction );
    helpMenu->addAction( aboutQtAction );
}

void MainWindow::createMenuBar()
{
    menuBar = new QMenuBar( );
    menuBar->addMenu( fileMenu );
    menuBar->addMenu( helpMenu );
}

void MainWindow::showWebPage( QString url )
{
    webview->setUrl( QUrl( url ) );
    webWidget->setWindowTitle( "" );
    webWidget->show();
    webview->show();
}

void MainWindow::showAbout()
{
    showWebPage( "qrc:/html/about.html" );
}

void MainWindow::showAboutQt()
{
    showWebPage( "https://www.qt.io/about-us/" );
}

void MainWindow::showControls()
{
    showWebPage( "qrc:/html/controls.html" );
}

void MainWindow::showLmgtfy()
{
    showWebPage( "http://bfy.tw/2M1q" );
}