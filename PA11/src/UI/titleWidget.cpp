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
    m_btnPlay->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%); outline: none;}");

    QIcon iconCross = QIcon( *m_imgCross );
    m_btnExit = new QPushButton( this );
    m_btnExit->setIcon( iconCross );
    m_btnExit->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%); outline: none;}");

    QIcon iconGear = QIcon( *m_imgGear );
    m_btnSettings = new QPushButton( this );
    m_btnSettings->setIcon( iconGear );
    m_btnSettings->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0%); outline: none;}");

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

#include <QDebug>
void TitleWidget::resize()
{
    float percentWidth = QWidget::width() / 1855.0f;
    float percentHeight = QWidget::height() / 1056.0f;

    m_lbBackground->setGeometry( 0, 0, QWidget::width(), QWidget::height() );

    m_btnPlay->setIconSize( QSize( 65 * percentWidth, 70 * percentHeight ) );
    m_btnPlay->setGeometry( QWidget::width() - (450.0f * percentWidth), QWidget::height() - (170 * percentHeight),
        80 * percentWidth, 80 * percentHeight );

    m_btnExit->setIconSize( QSize( 69 * percentWidth, 70 * percentHeight ) );
    m_btnExit->setGeometry( QWidget::width() - (350.0f * percentWidth), QWidget::height() - (170 * percentHeight),
        80 * percentWidth, 80 * percentHeight );

    m_btnSettings->setIconSize( QSize( 80 * percentWidth, 79 * percentHeight ) );
    m_btnSettings->setGeometry( QWidget::width() - (250.0f * percentWidth), QWidget::height() - (170 * percentHeight),
        80 * percentWidth, 80 * percentHeight );
}