#include "Player.h"
#include "myFunction.h"


Player::Player(BulletManager *bulletManager) :IObject()
{
	sprite = new CSprite("images/enemy.png");
	reloadTitle = new CSprite("images/reloadImg.png");
	reloadTitle->pos.x = 250;
	reloadTitle->pos.y = 200;
	reloadTitle->opacity = 0.0f;
	pos.x = 30;
	pos.y = BOTTOM;
	sprite->rotationCenter.x = sprite->width / 2;
	sprite->rotationCenter.y = sprite->height / 2;
	sprite->scalingCenter.x = sprite->width / 2;
	sprite->scalingCenter.y = sprite->height / 2;
	moveSpeed = 400.f;
	jumpSpeed = 700.f;
	destY = 250;
	isJumped = false;
	this->bulletManager = bulletManager;
	jumpCheck = false;
	bool pistolCheck = true;
	bool shotGunCheck = true;
	pistolReload = 18;
	shotGunReload = 5;
	bulletCheck = new Timer(3.0f);

}


Player::~Player()
{
	delete sprite;
	delete reloadTitle;
}


void Player::Update(float eTime)
{
	sprite->Update(eTime);
	reloadTitle->Update(eTime);

	if (MyKeyState('A') > 0)
	{
		pos.x -= moveSpeed *eTime;
		sprite->rot -= 0.3;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - sprite->width)
		{
			pos.x = WIDTH - sprite->width;
		}
	}
	if (MyKeyState('D') > 0)
	{
		pos.x += moveSpeed *eTime;
		sprite->rot += 0.3;
		if (pos.x < 0)
		{
			pos.x = 0;
		}
		else if (pos.x > WIDTH - sprite->width)
		{
			pos.x = WIDTH - sprite->width;
		}
	}
	if (MyKeyState(VK_SPACE) == 1 && isJumped == false)
	{

		isJumped = true;

	}
	if (isJumped == true)
	{
		Jump(eTime);
	}
	if (MyKeyState(VK_LBUTTON) == 1)
	{

		if (pistolReload > 0&&pistolCheck)
		{
			bulletManager->PushBullet(new Bullet(pos.x, pos.y));
			pistolReload -= 1;
		}
	}
	if (pistolReload <= 0)
	{
		pistolCheck = false;
		bulletCheck->Update(eTime);
		reloadTitle->opacity = 255;
		if (bulletCheck->isDone)
		{
			reloadTitle->opacity = 0;
			pistolCheck = true;
			pistolReload = 25;
		}

	}
}

void Player::Jump(float eTime)
{
	
	if (jumpCheck == false)
	{
		pos.y -= jumpSpeed * eTime;
		if (pos.y <= destY)
		{
			pos.y = destY;
			jumpCheck = true;
		}
	}
	if (jumpCheck)
	{
		pos.y += (jumpSpeed) * eTime;
		if (BOTTOM <= pos.y)
		{
			isJumped = false;
			pos.y = BOTTOM;
			jumpCheck = false;
		}
	}
}



void Player::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	reloadTitle->Render(pmat);
	sprite->Render(&(this->mat));
}
