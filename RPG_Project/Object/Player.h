#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 0.1;
	int AttackPoint = 2;
	
public:
	Player(float radius);
	~Player();

	void Update();
	void Render(HDC hdc);

	void MoveControl();

private:
	bool iskeyPreesed = false;
	class BulletManager* bulletManager;
	
};