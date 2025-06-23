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
	void FireBullet(Vector2 pos);
	bool IsCollision(Circle* circle);

private:
	Skill* skill;
	vector<Bullet*> bullets;

};