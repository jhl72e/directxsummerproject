#include "EnemyB.h"


EnemyB::EnemyB(int x, int y, Player *player) :Enemy(x,y)
{
	sprite = new CSprite("images/rock23.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	sprite->scalingCenter.x = sprite->width / 2;
	sprite->scalingCenter.y = sprite->height / 2;

	x = WIDTH+ sprite->width;
	
	destY = y - sprite->height / 2 + 53;
	moveSpeed = 500;
	isCeta = false;
	this->player = player;


}


EnemyB::~EnemyB()
{

}


void EnemyB::Attack(float eTime)
{

//if (pos.x < 0&&state==MOVING)
//	{
//		dir = 1;
//		pos.x = 0;
//		moveTimer->passedTime = 0;
//		moveTimer->Reset(1.f);
//	}
//	else if (pos.x > WIDTH - sprite->width&&state==MOVING)
//	{
//		dir = -1;
//		pos.x = WIDTH - sprite->width;
//		moveTimer->passedTime = 0;
//		//moveTimer->Reset(1.f);
//	}

	if (isCeta == false)
	{
		float h = player->pos.y - pos.y;
		float w = player->pos.x - pos.x;
		ceta = atan2(h, w);
		isCeta = true;
	}
	pos.x += cos(ceta) * 700 * eTime;
	sprite->rot -= 0.3;
	//pos.y += sin(ceta) * 700 * eTime;
	
}


