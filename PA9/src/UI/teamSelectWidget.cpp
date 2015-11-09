#include "teamSelectWidget.h"

TeamSelectWidget::TeamSelectWidget()
{
    // Allows keyboard input to fall through
    setFocusPolicy( Qt::ClickFocus );

    m_layout = new QGridLayout();

    m_imgLogos[0] = new QIcon( "images/Team Logos/Avalanches.png" );
    m_imgLogos[1] = new QIcon( "images/Team Logos/Blackhawks.png" );
    m_imgLogos[2] = new QIcon( "images/Team Logos/BlueJackets.png" );
    m_imgLogos[3] = new QIcon( "images/Team Logos/Blues.png" );
    m_imgLogos[4] = new QIcon( "images/Team Logos/Bruins.png" );
    m_imgLogos[5] = new QIcon( "images/Team Logos/Canadiens.png" );
    m_imgLogos[6] = new QIcon( "images/Team Logos/Canucks.png" );
    m_imgLogos[7] = new QIcon( "images/Team Logos/Capitals.png" );
    m_imgLogos[8] = new QIcon( "images/Team Logos/Coyotes.png" );
    m_imgLogos[9] = new QIcon( "images/Team Logos/Devils.png" );
    m_imgLogos[10] = new QIcon( "images/Team Logos/Ducks.png" );
    m_imgLogos[11] = new QIcon( "images/Team Logos/Flames.png" );
    m_imgLogos[12] = new QIcon( "images/Team Logos/Flyers.png" );
    m_imgLogos[13] = new QIcon( "images/Team Logos/Hurricanes.png" );
    m_imgLogos[14] = new QIcon( "images/Team Logos/Islanders.png" );
    m_imgLogos[15] = new QIcon( "images/Team Logos/Jets.png" );
    m_imgLogos[16] = new QIcon( "images/Team Logos/Kings.png" );
    m_imgLogos[17] = new QIcon( "images/Team Logos/Lightnings.png" );
    m_imgLogos[18] = new QIcon( "images/Team Logos/MapleLeafs.png" );
    m_imgLogos[19] = new QIcon( "images/Team Logos/Oilers.png" );
    m_imgLogos[20] = new QIcon( "images/Team Logos/Panthers.png" );
    m_imgLogos[21] = new QIcon( "images/Team Logos/Penguins.png" );
    m_imgLogos[22] = new QIcon( "images/Team Logos/Predators.png" );
    m_imgLogos[23] = new QIcon( "images/Team Logos/Rangers.png" );
    m_imgLogos[24] = new QIcon( "images/Team Logos/RedWings.png" );
    m_imgLogos[25] = new QIcon( "images/Team Logos/Sabres.png" );
    m_imgLogos[26] = new QIcon( "images/Team Logos/Senators.png" );
    m_imgLogos[27] = new QIcon( "images/Team Logos/Sharks.png" );
    m_imgLogos[28] = new QIcon( "images/Team Logos/Stars.png" );
    m_imgLogos[29] = new QIcon( "images/Team Logos/Wild.png" );

{
    QSizePolicy sizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    int total = 0;
    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 6; j++ )
        {
            m_btnLogos[total] = new QPushButton();
            m_btnLogos[total]->setFlat( true );
            sizePolicy.setHeightForWidth(
                m_btnLogos[total]->sizePolicy().hasHeightForWidth()) ;
            m_btnLogos[total]->setSizePolicy(sizePolicy);
            m_btnLogos[total]->setIcon( *(m_imgLogos[total]) );
            m_btnLogos[total]->setIconSize(
                QSize( m_btnLogos[total]->width(), 
                       m_btnLogos[total]->height() ) );

            m_layout->addWidget( m_btnLogos[total], i, j );
            total++;
        }
    }
}

    m_signalMapper = new QSignalMapper( this );

    connect( m_btnLogos[0], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[1], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[2], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[3], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[4], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[5], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[6], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[7], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[8], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[9], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[10], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[11], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[12], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[13], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[14], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[15], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[16], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[17], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[18], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[19], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[20], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[21], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[22], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[23], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[24], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[25], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[26], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[27], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[28], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );
    connect( m_btnLogos[29], SIGNAL ( released() ),
        m_signalMapper, SLOT( map() ) );


    m_signalMapper->setMapping( m_btnLogos[0], "Avalanches" );
    m_signalMapper->setMapping( m_btnLogos[1], "Blackhawks" );
    m_signalMapper->setMapping( m_btnLogos[2], "BlueJackets" );
    m_signalMapper->setMapping( m_btnLogos[3], "Blues" );
    m_signalMapper->setMapping( m_btnLogos[4], "Bruins" );
    m_signalMapper->setMapping( m_btnLogos[5], "Canadiens" );
    m_signalMapper->setMapping( m_btnLogos[6], "Canucks" );
    m_signalMapper->setMapping( m_btnLogos[7], "Capitals" );
    m_signalMapper->setMapping( m_btnLogos[8], "Coyotes" );
    m_signalMapper->setMapping( m_btnLogos[9], "Devils" );
    m_signalMapper->setMapping( m_btnLogos[10], "Ducks" );
    m_signalMapper->setMapping( m_btnLogos[11], "Flames" );
    m_signalMapper->setMapping( m_btnLogos[12], "Flyers" );
    m_signalMapper->setMapping( m_btnLogos[13], "Hurricanes" );
    m_signalMapper->setMapping( m_btnLogos[14], "Islanders" );
    m_signalMapper->setMapping( m_btnLogos[15], "Jets" );
    m_signalMapper->setMapping( m_btnLogos[16], "Kings" );
    m_signalMapper->setMapping( m_btnLogos[17], "Lightnings" );
    m_signalMapper->setMapping( m_btnLogos[18], "MapleLeafs" );
    m_signalMapper->setMapping( m_btnLogos[19], "Oilers" );
    m_signalMapper->setMapping( m_btnLogos[20], "Panthers" );
    m_signalMapper->setMapping( m_btnLogos[21], "Penguins" );
    m_signalMapper->setMapping( m_btnLogos[22], "Predators" );
    m_signalMapper->setMapping( m_btnLogos[23], "Rangers" );
    m_signalMapper->setMapping( m_btnLogos[24], "RedWings" );
    m_signalMapper->setMapping( m_btnLogos[25], "Sabres" );
    m_signalMapper->setMapping( m_btnLogos[26], "Senators" );
    m_signalMapper->setMapping( m_btnLogos[27], "Sharks" );
    m_signalMapper->setMapping( m_btnLogos[28], "Stars" );
    m_signalMapper->setMapping( m_btnLogos[29], "Wild" );

    connect( m_signalMapper, SIGNAL( mapped( QString ) ),
        this, SLOT( setTeams( QString ) ) );

    setLayout( m_layout );
}

TeamSelectWidget::~TeamSelectWidget()
{
    for( int i = 0; i < 30; i++ )
    {
        delete m_imgLogos[i];
        delete m_btnLogos[i];
    }
    delete m_layout;
    delete m_signalMapper;
}

void TeamSelectWidget::setTeams( QString team )
{
    static int selecting = 0;
    switch( selecting )
    {
        case 0:
            m_team1 = team;
            selecting++;
            break;
        case 1:
            m_team2 = team;
            selecting++;
            emit selectedTeams( m_team1, m_team2 );
            break;
        default:
            break;
    }
}

void TeamSelectWidget::resizeEvent( QResizeEvent* event )
{
    (void)event;
    int total = 0;
    for( int i = 0; i < 5; i++ )
    {
        for( int j = 0; j < 6; j++ )
        {
            m_btnLogos[total]->setIconSize(
                QSize( m_btnLogos[total]->width(), 
                       m_btnLogos[total]->height() ) );
            total++;
        }
    }
}