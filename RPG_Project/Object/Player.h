#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 0.1;
	int AttakPoint = 2;

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

	int GetPlayerAttakPoint() { return AttakPoint; }

private:
	bool iskeyPreesed = false;
	static Player* instance;
	float2 firePos = {};
	HPEN hPen;
	
	
};