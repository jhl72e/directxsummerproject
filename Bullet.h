#pragma once
#include "IObject.h"
#include "Sprite.h"

class Bullet :
	public IObject
{
public:

	bool isCeta;
	float h;
	float w;
	float ceta;
	int bulletSpeed;
	CSprite *sprite;
	Bullet(int x,int y);
	~Bullet();
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
};

