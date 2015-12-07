#ifndef WIN_WIDGET
#define WIN_WIDGET

#include <QApplication>
#include <QOpenGLWidget>
#include <QPixmap>
#include <QLabel>

class WinWidget   :   public QOpenGLWidget
{
    Q_OBJECT

public:
    WinWidget();
    ~WinWidget();

protected:
    virtual void resizeEvent( QResizeEvent* event );

private:
    void resize();

    QLabel* m_lbBackground;

    QPixmap* m_imgBackground;
};

#endif  //  WIN_WIDGET