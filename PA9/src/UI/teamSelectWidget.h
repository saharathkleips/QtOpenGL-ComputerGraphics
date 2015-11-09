#ifndef TEAM_SELECT_WIDGET
#define TEAM_SELECT_WIDGET

#include <QApplication>
#include <QOpenGLWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QSignalMapper>

class TeamSelectWidget    :   public QOpenGLWidget
{
    Q_OBJECT

public:
    TeamSelectWidget();
    ~TeamSelectWidget();

protected:
    virtual void resizeEvent( QResizeEvent* event );

signals:
    void selectedTeams( QString team1, QString team2 );
    void clickedTeam( QString team );

public slots:
    void setTeams( QString team );

private:
    QPushButton* m_btnLogos[30];
    QIcon* m_imgLogos[30];

    QGridLayout* m_layout;
    QSignalMapper* m_signalMapper;

    QString m_team1, m_team2;
};

#endif  //  TEAM_SELECT_WIDGET