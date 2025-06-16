#pragma once

class Monster : public Circle
{
private:
	float AttackPoint = 1.0f;
	float speed = 0.1f;
public:

	Monster(float radius);
	~Monster();

	void colision();

private:
	



};