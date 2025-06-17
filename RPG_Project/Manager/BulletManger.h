#pragma once
#include "framework.h"

class BulletManager
{
private:
	int bulletPoolSize = 10;


	BulletManager();
	~BulletManager();

public:
	static BulletManager* GET()
	{
		if (instance == nullptr)
		{
			instance = new BulletManager();
		}
		return instance;
	}
	static void Delete()
	{
		delete instance;
	}

	void Update();
	void Render(HDC hdc);
	void FireBullet(float2 pos);
	bool IsCollision(Circle* circle);

private:
	static BulletManager* instance;
	vector<Bullet*> bullets;

};