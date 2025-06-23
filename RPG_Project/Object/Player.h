#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 200;
	int attakPoint = 2;

	Player(float radius);
	~Player();
	
	
public:

	static Player* Get()
	{
		if (instance == nullptr)
		{
			instance = new Player(30);
		}
		return instance;

	}
	static void Delete()
	{
		delete instance;
	}

	void Update();
	void Render(HDC hdc);

	void MoveControl();
	void LineOut();
	void DrawLine(HDC hdc);
	void gauge(HDC hdc);
	void gaugeUpdate();
	int GetPlayerAttakPoint() { return attakPoint; }

private:
	bool iskeyPreesed = false;
	static Player* instance;
	Vector2 firePos = {};
	HPEN hPen;



	float maxCharge = 10;
	float currentCharge = 0;
	float chargeSpeed = 0.005;
	bool isCharging;
	
	Skill* skill;
	
};