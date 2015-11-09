#include "mainMenuWidget.h"

MainMenuWidget::MainMenuWidget()
{
	// Allows keyboard input to fall through
    setFocusPolicy( Qt::ClickFocus );

    // Create Images
    m_imgBackground = new QPixmap( "images/Background.jpg" );
    m_imgLeftPlayer = new QPixmap( "images/PlayerLeft.png" );
    m_imgRightPlayer = new QPixmap( "images/PlayerRight.png" );
    m_imgNhlLogo = new QPixmap( "images/NHLLogo.png" );

    // Create Labels
    m_lbBackground = new QLabel( this );
    m_lbBackground->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbBackground->setPixmap( *m_imgBackground );
    m_lbBackground->setScaledContents( true );

    m_lbNhlLogo = new QLabel( this );
    m_lbNhlLogo->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbNhlLogo->setPixmap( *m_imgNhlLogo );
    m_lbNhlLogo->setScaledContents( true );

    m_lbLeftPlayer = new QLabel( this );
    m_lbLeftPlayer->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbLeftPlayer->setPixmap( *m_imgLeftPlayer );
    m_lbLeftPlayer->setScaledContents( true );

    m_lbRightPlayer = new QLabel( this );
    m_lbRightPlayer->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbRightPlayer->setPixmap( *m_imgRightPlayer );
    m_lbRightPlayer->setScaledContents( true );

  	QFont NHLFont( "NHL", 20 );
    // Create Menu Buttons
	m_btnSinglePlayer = new QPushButton( "SINGLE PLAYER", this );
	m_btnSinglePlayer->setFont( NHLFont );
	m_btnSinglePlayer->setFlat( true );
	m_btnSinglePlayer->setStyleSheet("color: blue");
	m_btnTwoPlayer = new QPushButton( "VERSUS MODE", this );
	m_btnTwoPlayer->setFont( NHLFont );
	m_btnTwoPlayer->setFlat( true );
	m_btnTwoPlayer->setStyleSheet("color: blue");
	m_btnExit = new QPushButton( "EXIT GAME", this );
	m_btnExit->setFont( NHLFont );
	m_btnExit->setFlat( true );
	m_btnExit->setStyleSheet("color: blue");

	resize();

	connect( m_btnSinglePlayer, SIGNAL ( released() ), 
		this, SIGNAL ( clickedSinglePlayer() ) );
	connect( m_btnTwoPlayer, SIGNAL ( released() ), 
		this, SIGNAL ( clickedTwoPlayer() ) );
	connect( m_btnExit, SIGNAL ( released() ), 
		this, SIGNAL ( clickedExit() ) );
}

MainMenuWidget::~MainMenuWidget()
{
    delete m_lbBackground;
    delete m_lbLeftPlayer;
    delete m_lbRightPlayer;
    delete m_lbNhlLogo;

	delete m_btnSinglePlayer;
	delete m_btnTwoPlayer;
	delete m_btnExit;

    delete m_imgBackground;
    delete m_imgLeftPlayer;
    delete m_imgRightPlayer;
    delete m_imgNhlLogo;
}

void MainMenuWidget::resizeEvent( QResizeEvent* event )
{
	(void)event;

	resize();
}

void MainMenuWidget::resize()
{
	m_lbBackground->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
	m_lbNhlLogo->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbLeftPlayer->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_lbRightPlayer->setGeometry( 0, 0, QWidget::width(), QWidget::height() );

	m_btnSinglePlayer->setGeometry( 
		QWidget::width() / 2 - m_btnSinglePlayer->width() / 2, 
		QWidget::height() - m_btnSinglePlayer->height() / 2 - 150, 250, 40);
	m_btnTwoPlayer->setGeometry( 
		QWidget::width() / 2 - m_btnTwoPlayer->width() / 2, 
		QWidget::height() - m_btnTwoPlayer->height() / 2 - 100, 250, 40 );
	m_btnExit->setGeometry( QWidget::width() / 2 - m_btnExit->width() / 2, 
		QWidget::height() - m_btnExit->height() / 2 - 50, 250, 40 );
}