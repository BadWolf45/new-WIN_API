#include "framework.h"

Monster::Monster(float radius) : Circle(radius)
{
	center = { 400,300 };
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hbluebrush = CreateSolidBrush(RGB(0, 0, 255));
	
}

Monster::~Monster()
{
	DeleteObject(hRedBrush);
	DeleteObject(hbluebrush);
}

void Monster::Update()
{
	if (isColisionPoint(mousePos))
	{
		hselectBrush =  hRedBrush;
	}
	else
	{
		hselectBrush = hbluebrush;
	}
	
	if (BulletManager::GET()->IsCollision(this) == true)
	{
		isActive = false;
	}
}

void Monster::Render(HDC hdc)
{
	SelectObject(hdc, hselectBrush);
	Circle::Render(hdc);
}




