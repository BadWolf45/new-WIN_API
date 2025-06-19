#pragma once

class Monster : public Circle
{
private:
	float AttackPoint = 1.0f;
	float speed = 100.0f;

	int mexHealthPoint = 5;
	int mexManaPoint = 3;
public:

	Monster(float radius);
	~Monster();

	void Update();
	void Render(HDC hdc);
	void MonsterMove();
	int SetHP(int HP) { healthPoint = HP; }
	int GetHP() { return mexHealthPoint; }
private:
	int healthPoint = mexHealthPoint;
	int manaPoint = mexManaPoint;
	HBRUSH hRedBrush;
	HBRUSH hbluebrush;
	HBRUSH hselectBrush;

};