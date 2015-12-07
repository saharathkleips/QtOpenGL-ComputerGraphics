#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QProcess>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "oglWidget.h"
#include "titleWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void swapToTitle();
    void swapToGame();
    void restartGame();

private:
    void createActions();
    void createMenus();
    void createMenuBar();

    OGLWidget* oglWidget;
    TitleWidget* titleWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionPauseProgram;
    QAction* actionRestartGame;
    QAction* actionExitProgram;
};

#endif  //  MAIN_WINDOW_H