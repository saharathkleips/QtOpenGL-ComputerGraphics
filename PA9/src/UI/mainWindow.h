#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

#include "mainMenuWidget.h"
#include "oglWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void swapToTeamSelect();
    void swapToGame();

private:
    void createActions();
    void createMenus();
    void createMenuBar();


    OGLWidget* oglWidget;
    MainMenuWidget* mainMenuWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionExitProgram;
};

#endif  //  MAIN_WINDOW_H