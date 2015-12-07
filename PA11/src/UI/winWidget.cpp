#include "winWidget.h"

WinWidget::WinWidget()
{
    setFocusPolicy( Qt::ClickFocus );

    m_imgBackground = new QPixmap( "images/WinScreen.jpg" );

    m_lbBackground = new QLabel( this );
    m_lbBackground->setPixmap( *m_imgBackground );
    m_lbBackground->setScaledContents( true );

    resize();
}

WinWidget::~WinWidget()
{
    delete m_imgBackground;
}

void WinWidget::resizeEvent( QResizeEvent* event )
{
    (void)event;
    resize();
}

void WinWidget::resize()
{
    m_lbBackground->setGeometry( 0, 0, QWidget::width(), QWidget::height() );
}