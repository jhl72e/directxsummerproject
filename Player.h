#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "BulletManager.h"
#include "Timer.h"

class Player :
	public IObject
{
public:

	int shotGunReload;
	int pistolReload;

	Timer *bulletCheck;
	bool isJumped;
	bool jumpCheck;
	bool pistolCheck;
	bool shotGunCheck;
	float jumpSpeed;
	CSprite *sprite;
	CSprite *reloadTitle;
	float moveSpeed;
	BulletManager *bulletManager;
	Player(BulletManager *bulletManager);
	~Player();
	int destY;
	
	void Update(float eTime);
	void Jump(float eTime);
	void Render(D3DXMATRIX *pmat);
};

