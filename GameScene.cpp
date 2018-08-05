#include "GameScene.h"
#include "myFunction.h"

GameScene::GameScene()
{
	enemyManager = new EnemyManager();
	bulletManager = new BulletManager();

	player = new Player(bulletManager);
	spawnTimer = new Timer(1.0f);
	background = new CSprite("images/backgroundTest022.png");
	backgroundBack = new CSprite("images/bgTest.png");
}


GameScene::~GameScene()
{
	delete player;
	delete bulletManager;
	delete enemyManager;
	delete spawnTimer;
	delete background;
	delete backgroundBack;
	
}

void GameScene::Update(float eTime)
{
	backGroundMove(eTime);
	player->Update(eTime);
	bulletManager->Update(eTime);
	enemyManager->Update(eTime);
	spawnTimer->Update(eTime);
	if (spawnTimer->isDone)
		SpawnEnemy();

	CollisionCheck(eTime);
	if (player->isDelete)
	{
		ChangeScene(new EndScene());
		return;
	}
	
}

void GameScene::Render()
{
	background->Render(0);
	backgroundBack->Render(0);
	player->Render(0);
	bulletManager->Render(0);
	enemyManager->Render(0);
	 
	
	
}

void GameScene::SpawnEnemy()
{
	int x = rand() % (WIDTH-200)+100;
	int r = rand() % 2;
	
	if (r == 0)
	{
		enemyManager->PushEnemy(new EnemyA(rand()%(WIDTH-300),BOTTOM));
	}
	else
		enemyManager->PushEnemy(new EnemyB(rand() % (WIDTH-300), BOTTOM, player));
}


void GameScene::CollisionCheck(float eTime)
{
	EnemyList::iterator eiter;
	for (eiter = enemyManager->eList.begin(); eiter != enemyManager->eList.end(); eiter++)
	{
		BulletList::iterator biter;
		for (biter = bulletManager->bList.begin(); biter != bulletManager->bList.end(); biter++)
		{
	
			if (GetDistance((*eiter)->pos + D3DXVECTOR2((*eiter)->sprite->width / 2, (*eiter)->sprite->height / 2),
				(*biter)->pos + D3DXVECTOR2((*biter)->sprite->width / 2, (*biter)->sprite->height / 2)) < (*eiter)->sprite->height)
			{
				
				if ((*eiter)->dieCheck == 5)
				{
					(*eiter)->isDelete = true;
					(*biter)->isDelete = true;
				}
				else
				{
					(*eiter)->dieCheck++;
					


				}
			}	
		}
		if (GetDistance((*eiter)->pos + D3DXVECTOR2((*eiter)->sprite->width / 2, (*eiter)->sprite->height / 2),
			player->pos + D3DXVECTOR2(player->sprite->width / 2, player->sprite->height / 2)) < 100)
		{
			player->isDelete = true;
			
		}
	}
}

void GameScene::backGroundMove(float eTime)
{
	background->pos.y = 580;
	background->pos.x -= 1000 * eTime;
	backgroundBack->pos.x -= 100 * eTime;
	if (background->pos.x <= -1280)
	{
		background->pos.x = 0;
	}
	if (backgroundBack->pos.x <= -1280)
	{
		backgroundBack->pos.x = 0;
	}
	
	
}

