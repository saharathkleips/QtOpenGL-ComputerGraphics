#include "titleWidget.h"

TitleWidget::TitleWidget()
{
    setFocusPolicy( Qt::ClickFocus );

    m_imgBackground = new QPixmap( "images/TitleScreen.jpg" );
    m_imgCross = new QPixmap( "images/Cross.png" );
    m_imgGear = new QPixmap( "images/Gear.png" );
    m_imgPlay = new QPixmap( "images/Play.png" );

    m_lbBackground = new QLabel( this );
    m_lbBackground->setPixmap( *m_imgBackground );
    m_lbBackground->setScaledContents( true );

    QIcon iconPlay = QIcon( *m_imgPlay );
    m_btnPlay = new QPushButton( this );
    m_btnPlay->setIcon( iconPlay );
    m_btnPlay->setIconSize( QSize( 65, 70 ) );
    m_btnPlay->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%);}");

    QIcon iconCross = QIcon( *m_imgCross );
    m_btnExit = new QPushButton( this );
    m_btnExit->setIcon( iconCross );
    m_btnExit->setIconSize( QSize( 69, 70 ) );
    m_btnExit->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%);}");

    QIcon iconGear = QIcon( *m_imgGear );
    m_btnSettings = new QPushButton( this );
    m_btnSettings->setIcon( iconGear );
    m_btnSettings->setIconSize( QSize( 80, 79 ) );
    m_btnSettings->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%);}");

    resize();

    connect( m_btnPlay, SIGNAL( released() ), this, SIGNAL( clickedPlay() ) );
    connect( m_btnSettings, SIGNAL( released() ), this, 
        SIGNAL( clickedSettings () ) );
    connect( m_btnExit, SIGNAL( released() ), this, SIGNAL( clickedExit() ) );
}

TitleWidget::~TitleWidget()
{
    delete m_imgBackground;
    delete m_imgCross;
    delete m_imgGear;
    delete m_imgPlay;
    delete m_lbBackground;
    delete m_btnPlay;
    delete m_btnExit;
    delete m_btnSettings;
}

void TitleWidget::resizeEvent( QResizeEvent* event )
{
    (void)event;
    resize();
}

void TitleWidget::resize()
{
    m_lbBackground->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
    m_btnPlay->setGeometry( QWidget::width() - 450, QWidget::height() - 170,
        80, 80 );
    m_btnExit->setGeometry( QWidget::width() - 350, QWidget::height() - 170,
        80, 80 );
    m_btnSettings->setGeometry( QWidget::width() - 250, QWidget::height() - 170,
        80, 80 );
}