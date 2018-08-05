#pragma once
#include "Bullet.h"
#include <list>

typedef std::list<Bullet*>BulletList;

class BulletManager
{
public:
	BulletList bList;
	BulletManager();
	~BulletManager();
	void Update(float eTime);
	void Render(D3DXMATRIX *pmat);
	void PushBullet(Bullet *pb);
	BulletList::iterator PopBullet(BulletList::iterator iter);
};

