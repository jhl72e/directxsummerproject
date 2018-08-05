#include "EnemyA.h"


EnemyA::EnemyA(int x, int y) :Enemy(x,y)
{
	sprite = new CSprite("images/rock.png");
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	//sprite->scalingCenter.x = sprite->width / 2;
	//sprite->scalingCenter.y = sprite->height / 2;
	pos.y =500;
	destY = y - sprite->height/2+13;
	pos.x =  WIDTH + sprite->height;

}


EnemyA::~EnemyA()
{

}

void EnemyA::Attack(float eTime)
{
	/*if (pos.x < 0)
	{
		dir = 1;
		pos.x = 0;
		moveTimer->passedTime = 0;
		moveTimer->Reset(1.f);
	}
	else if (pos.x > WIDTH - sprite->width)
	{
		dir = -1;
		pos.x = WIDTH - sprite->width;
		moveTimer->passedTime = 0;
		moveTimer->Reset(1.f);
	}*/
	
	pos.x -= 500 * eTime;
	sprite->rot -= 0.3;

}



void EnemyA::Move(float eTime)
{
	
		state = State::ATTACKING;

}