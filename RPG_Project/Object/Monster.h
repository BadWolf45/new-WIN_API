#pragma once

class Monster : public Circle
{
private:
	float AttackPoint = 1.0f;
	float speed = 100.0f;

	float fireTime = 0;
	float fireinter = 1;

	int fireCount = 10;

	int mexHealthPoint = 5;
	int mexManaPoint = 3;
public:

	Monster(float radius);
	~Monster();

	void Update();
	void Render(HDC hdc);
	void MonsterMove();
	void Damage();
	void Fire();
	void MultiShot();

	void SetPlayer(Player* player) { this->player = player; }

	int SetHP(int HP) { healthPoint = HP; }
	int GetHP() { return mexHealthPoint; }
private:
	int healthPoint = mexHealthPoint;
	int manaPoint = mexManaPoint;
	HBRUSH hRedBrush;
	HBRUSH hbluebrush;
	HBRUSH hselectBrush;

	Player* player = nullptr;
	float angle = 0.0f;
};