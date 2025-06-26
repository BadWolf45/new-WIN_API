#pragma once
#include "framework.h"

class BulletManager : public Singleton<BulletManager>
{
	friend class Singleton;
private:
	int bulletPoolSize = 200;


	BulletManager();
	~BulletManager();

public:


	void Update();
	void Render(HDC hdc);
	void FireBullet(Vector2 pos, string tag, Vector2 direction = Vector2::Up());
	bool IsCollision(Circle* circle, string tag);

private:
	Skill* skill;
	vector<Bullet*> bullets;

};