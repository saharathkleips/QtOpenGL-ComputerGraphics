#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "oglWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void restartGame();

private:
    void createActions();
    void createMenus();
    void createMenuBar();

    OGLWidget* oglWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionRestartGame;
    QAction* actionExitProgram;
};

#endif  //  MAIN_WINDOW_H