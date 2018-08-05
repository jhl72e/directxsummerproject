#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "Timer.h"
#include "Def.h"
class Enemy :
	public IObject
{
public:
	enum State
	{
		SPAWNING,
		MOVING,
		ATTACKING
	};

	CSprite *sprite;

	Enemy(int x, int y);
	Timer *moveTimer;
	int dir;
	int moveSpeed;
	State state;
	int destY;
	int moveCnt;
	int dieCheck;


	Enemy();
	virtual	~Enemy();

	virtual void Update(float eTime);
	virtual void Attack(float eTime);
	virtual void Move(float eTime);
	void SpawnMove(float eTime);

	void Render(D3DXMATRIX *pmat);
};

