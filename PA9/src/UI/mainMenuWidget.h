#ifndef MAIN_MENU_WIDGET
#define MAIN_MENU_WIDGET

#include <QApplication>
#include <QOpenGLWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QFont>
#include <QPixmap>
#include <QLabel>

class MainMenuWidget 	:	public QOpenGLWidget
{
	Q_OBJECT

public:
	MainMenuWidget();
	~MainMenuWidget();

signals:
    void clickedSinglePlayer();
    void clickedTwoPlayer();
    void clickedExit();

protected:
	virtual void resizeEvent( QResizeEvent* event );

private:
    void resize();

    QLabel* m_lbBackground;
    QLabel* m_lbLeftPlayer;
    QLabel* m_lbRightPlayer;
    QLabel* m_lbNhlLogo;

	QPushButton* m_btnSinglePlayer;
	QPushButton* m_btnTwoPlayer;
	QPushButton* m_btnExit;

    QPixmap* m_imgBackground;
    QPixmap* m_imgLeftPlayer;
    QPixmap* m_imgRightPlayer;
    QPixmap* m_imgNhlLogo;
};

#endif	//	MAIN_MENU_WIDGET