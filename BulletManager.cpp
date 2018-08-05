#include "BulletManager.h"


BulletManager::BulletManager()
{

}


BulletManager::~BulletManager()
{
	BulletList::iterator iter;
	for (iter = bList.begin(); iter != bList.end(); iter++)
	{
		delete (*iter);
	}
}


void BulletManager::Update(float eTime)
{
	BulletList::iterator iter;
	for (iter = bList.begin(); iter != bList.end(); iter++)
	{

		(*iter)->Update(eTime);
		if ((*iter)->isDelete)
		{
			iter = PopBullet(iter);
			if (iter == bList.end())
			{
				break;
			}
		}
	}
}

void BulletManager::Render(D3DXMATRIX *pmat)
{
	BulletList::iterator iter;
	for (iter = bList.begin(); iter != bList.end(); iter++)
		(*iter)->Render(pmat);
}

void BulletManager::PushBullet(Bullet *pb)
{
	bList.push_back(pb);
}

BulletList::iterator BulletManager::PopBullet(BulletList::iterator iter)
{
	delete (*iter);
	iter =bList.erase(iter);
	return iter;
}