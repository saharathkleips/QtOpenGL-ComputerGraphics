#include "hockeyTable.h"
#include <QFileInfo>

/**
 * @brief      Default constructor for Hockey Table.
 */
HockeyTable::HockeyTable()
	:	ColorPhysicsEntity( btTransform( btQuaternion( 0, 0, 0, 1 ), 
		btVector3( 0, 0, 0 ) ), 0, "models/HockeyTable.obj" )
{
	player = new QMediaPlayer(); 
    const QString file = "sounds/hum.mp3";
    QUrl url = QUrl::fromLocalFile(QFileInfo(file).absoluteFilePath());
    player->setMedia(url);
    player->setVolume(800);	
    player->play();
}

/**
 * @brief      Overloaded update function.
 * @details    Plays a huming sound to simulate air.
 */
void HockeyTable::update(){

	if(QMediaPlayer::StoppedState){
    	player->play();
	}

    ColorPhysicsEntity::update();
}