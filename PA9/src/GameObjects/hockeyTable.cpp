#include "hockeyTable.h"
#include <QFileInfo>

HockeyTable::HockeyTable()
	:	ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
		btVector3( 0, 0, 0 ) ), 0, "models/HockeyTable.obj" )
{
	player = new QMediaPlayer(); 
    // player->setMedia(QUrl::fromLocalFile("/home/ben/Desktop/cs480Kleips/PA9/src/Sounds/hum.mp3"));
    const QString file = "sounds/hum.mp3";
    QUrl url = QUrl::fromLocalFile(QFileInfo(file).absoluteFilePath());
    player->setMedia(url);
    player->setVolume(800);	
    player->play();
}

void HockeyTable::update(){

	if(QMediaPlayer::StoppedState){
    	player->play();
	}

    ColorPhysicsEntity::update();
}