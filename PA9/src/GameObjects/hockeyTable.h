#ifndef HOCKEY_TABLE_H
#define HOCKEY_TABLE_H

#include <QMediaPlayer>
#include "Entity/colorPhysicsEntity.h"


class HockeyTable	:	public ColorPhysicsEntity
{
public:
	HockeyTable();
	void update();

private:
	QMediaPlayer *player;
};



#endif	//	HOCKEY_TABLE_H