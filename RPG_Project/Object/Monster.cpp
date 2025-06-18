#include "framework.h"

Monster::Monster(float radius) : Circle(radius)
{
	center = { 500,-50 };
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
	MonsterMove();
	if (isColisionPoint(mousePos))
	{
		hselectBrush =  hRedBrush;
	}
	else
	{
		hselectBrush = hbluebrush;
	}
	
	if (BulletManager::GET()->IsCollision(this))
	{
		int P =Player::Get()->GetPlayerAttakPoint();
		HealthPoint -= P;
		if (HealthPoint <= 0)
		{
			isActive = false;
			center = { 500,-50 };
			isActive = true;

		}
		
	}


	
}

void Monster::Render(HDC hdc)
{
	SelectObject(hdc, hselectBrush);
	Circle::Render(hdc);
}

void Monster::MonsterMove()
{
	center.y += speed;
	if (center.y - radius >= SCREEN_HEIGHT)
	{
		isActive = false;
		center = { 500,-50 };
		isActive = true;
	}
}





