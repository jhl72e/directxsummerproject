#include "Bullet.h"
#include "myFunction.h"

Bullet::Bullet(int x, int y) : IObject()
{
	sprite = new CSprite("images/Bullet2.png");
	pos.x = x;
	pos.y = y;
	isCeta = false;
	h = 0;
	w = 0;
	ceta = 0.f;
	bulletSpeed = 1500;
}

Bullet::~Bullet()
{
	delete sprite;
}

void Bullet::Update(float eTime)
{
	 if(isCeta == false)
		{
			float h = MyGetCursorPos().y - pos.y;
			float w = MyGetCursorPos().x - pos.x;
			ceta = atan2(h, w);
			sprite->rot += ceta;
				isCeta = true;
		}
	pos.x += cos(ceta) * bulletSpeed* eTime;
	pos.y += sin(ceta) * bulletSpeed* eTime;
	sprite->Update(eTime);
}

void Bullet::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	sprite->Render(&mat);
}
