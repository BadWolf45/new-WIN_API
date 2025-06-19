#pragma once
#include "framework.h"

class BulletManager : public Singleton<BulletManager>
{
	friend class Singleton;
private:
	int bulletPoolSize = 10;


	BulletManager();
	~BulletManager();

public:


	void Update();
	void Render(HDC hdc);
	void FireBullet(float2 pos, int AttackPoint);
	bool IsCollision(Circle* circle);

private:

	vector<Bullet*> bullets;

};