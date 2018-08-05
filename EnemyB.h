	#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Def.h"
class EnemyB :
	public Enemy
{
public:


	EnemyB(int x, int y, Player *player);
	~EnemyB();
	float ceta;
	bool isCeta;
	Player *player;
	void Attack(float eTime);
};

