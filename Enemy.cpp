
#include "Enemy.h"
#include "Def.h"

Enemy::Enemy(int x, int y) :IObject()
{
	pos.x = x;
	pos.y = 20;
	moveTimer = new Timer(3.f);
	dir = (rand() % 2) * 2 - 1;
	moveSpeed = 300;
	state = State::SPAWNING;
	moveCnt = 0;
	dieCheck = 0;
}


Enemy::~Enemy()
{
	delete sprite;
}

void Enemy::Update(float eTime)
{
	if (state == SPAWNING)
	{
		SpawnMove(eTime);
	}
	else if (state == MOVING)
	{
		Move(eTime);
	}
	else if (state == ATTACKING)
	{
		Attack(eTime);
	}
}

void Enemy::Attack(float eTime)
{

}

void Enemy::Move(float eTime)
{
	moveTimer->Update(eTime);
	if (moveTimer->isDone)
	{
		//dir = -dir;
		moveCnt++;
	}

	if (pos.x < 0)
	{
		dir = 1;
		pos.x = 0;
		sprite->rot += 0.3;
		moveTimer->passedTime = 0;
		moveTimer->Reset(1.f);
	}
	else if (pos.x > WIDTH - sprite->width)
	{
		dir = -1;
		sprite->rot -= 0.3;
		pos.x = WIDTH - sprite->width;
		moveTimer->passedTime = 0;
		moveTimer->Reset(1.f);
	}

	pos.x += dir * moveSpeed * eTime;
	sprite->rot -= 0.3;
	if (moveCnt == 2)
	{
		state = State::ATTACKING;
	}

}

void Enemy::SpawnMove(float eTime)
{
	pos.y += 400 * eTime;
	sprite->rot -= 0.3;
	if (pos.y >= destY)
	{
		pos.y = destY;
		state = State::MOVING;
	}
}

void Enemy::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	sprite->Render(&mat);
}

