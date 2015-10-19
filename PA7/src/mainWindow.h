#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QKeySequence>

#include "oglWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected slots:
void updatePauseActionText();
void showAbout();
void showAboutQt();
void showControls();
void showLmgtfy();

private:
    void createActions();
    void createMenus();
    void createMenuBar();

    void showWebPage( QString url );

    OGLWidget* oglWidget;

    QWidget* webWidget;
    QWebView* webview;

    QMenuBar* menuBar;

    QMenu* fileMenu;
    QAction* pauseAction;
    QAction* exitAction;

    QMenu* helpMenu;
    QAction* aboutAction;
    QAction* aboutQtAction;
    QAction* controlsAction;
    QAction* moreHelpAction;
};

#endif  //  MAIN_WINDOW_H