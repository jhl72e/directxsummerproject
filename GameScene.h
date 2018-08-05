#pragma once
#include "IScene.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyManager.h"
#include "Timer.h"
#include "Sprite.h"
#include "Def.h"
#include "myFunction.h"
#include "EndScene.h"


class GameScene :
	public IScene
{
public:
	enum State
	{
		SPAWNING,
		MOVING,
		ATTACKING
	};
	BulletManager *bulletManager;
	EnemyManager *enemyManager;

	CSprite *background;
	CSprite *backgroundBack;
	Timer *spawnTimer;
	Player *player;
	EnemyA *eA;
	EnemyB *eB;
	bool flag = false;
	GameScene();
	~GameScene();
	float EnemyPos;
	void SpawnEnemy();
	void Update(float eTime);
	void Render();
	void CollisionCheck(float eTime);
	void backGroundMove(float eTime);
	
};

