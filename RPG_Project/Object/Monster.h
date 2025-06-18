#pragma once

class Monster : public Circle
{
private:
	float AttackPoint = 1.0f;
	float speed = 0.1f;

	int MexHealthPoint = 5;
	int MexManaPoint = 3;
public:

	Monster(float radius);
	~Monster();

	void Update();
	void Render(HDC hdc);
	void MonsterMove();

private:
	int HealthPoint = MexHealthPoint;
	int ManaPoint = MexManaPoint;
	HBRUSH hRedBrush;
	HBRUSH hbluebrush;
	HBRUSH hselectBrush;

};