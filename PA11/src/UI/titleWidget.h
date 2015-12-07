#ifndef TITLE_WIDGET
#define TITLE_WIDGET

#include <QApplication>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>

class TitleWidget   :   public QOpenGLWidget
{
    Q_OBJECT

public:
    TitleWidget();
    ~TitleWidget();

signals:
    void clickedPlay();
    void clickedSettings();
    void clickedExit();

protected:
    virtual void resizeEvent( QResizeEvent* event );

private:
    void resize();

    QLabel* m_lbBackground;

    QPushButton* m_btnPlay;
    QPushButton* m_btnExit;
    QPushButton* m_btnSettings;

    QPixmap* m_imgBackground;
    QPixmap* m_imgPlay;
    QPixmap* m_imgGear;
    QPixmap* m_imgCross;
};

#endif  //  TITLE_WIDGET