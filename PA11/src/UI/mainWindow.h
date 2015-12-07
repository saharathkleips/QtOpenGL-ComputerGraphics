#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QProcess>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "oglWidget.h"
#include "titleWidget.h"
#include "winWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void swapToTitle();
    void swapToGame();
    void swapToWin();
    void restartGame();

private:
    void createActions();
    void createMenus();
    void createMenuBar();

    OGLWidget* oglWidget;
    TitleWidget* titleWidget;
    WinWidget* winWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionRestartGame;
    QAction* actionExitProgram;
};

#endif  //  MAIN_WINDOW_H