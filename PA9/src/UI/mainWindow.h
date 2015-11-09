#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QKeySequence>
#include <QSignalMapper>

#include "mainMenuWidget.h"
#include "teamSelectWidget.h"
#include "oglWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void swapToTeamSelect();
    void swapToGame( QString team1, QString team2 );

private:
    void createActions();
    void createMenus();
    void createMenuBar();


    OGLWidget* oglWidget;
    MainMenuWidget* mainMenuWidget;
    TeamSelectWidget* teamSelectWidget;

    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionPauseProgram;
    QAction* actionExitProgram;

    QMenu* menuCamera;

    QSignalMapper* m_signalMapper;
    QAction* actionSideAngled;
    QAction* actionBehindPlayer1;
    QAction* actionBehindPlayer2;
    QAction* actionTopDown;
};

#endif  //  MAIN_WINDOW_H