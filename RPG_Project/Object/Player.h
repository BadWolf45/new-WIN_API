#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 200;
	int attakPoint = 2;
	float aimLenght = 50.0f;
	
public:
	Player(float radius);
	~Player();
	
	


	

	void Update();
	void Render(HDC hdc);

	void MoveControl();
	void LineOut();
	void DrawLine(HDC hdc);
	void gauge(HDC hdc);
	void gaugeUpdate();
	void KeybordMove();
	void MouseControl();

	void aiming();

	int GetPlayerAttakPoint() { return attakPoint; }

private:
	bool iskeyPreesed = false;
	Vector2 firePos = {};
	HPEN hPen;



	float maxCharge = 10;
	float currentCharge = 0;
	float chargeSpeed = 0.005;
	bool isCharging;
	
	float angle = PI * 0.5;

	Vector2 aimPoint;
	
};