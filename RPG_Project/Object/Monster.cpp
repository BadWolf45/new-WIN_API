#include "framework.h"
#include "monster.h"
#include "monster.h"
#include "monster.h"
#include "monster.h"
#include "monster.h"

Monster::Monster(float radius) : Circle(radius)
{
	
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
	if (!isActive) { return; }
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
		healthPoint -= P;
		if (healthPoint <= 0)
		{
			healthPoint = mexHealthPoint;
			isActive = false;
			
		}
		
	}

	if 

}

void Monster::Render(HDC hdc)
{
	if (!isActive) { return; }
	HBRUSH defaoltBrush1 =  (HBRUSH)SelectObject(hdc, hselectBrush);
	Circle::Render(hdc);

	SelectObject(hdc, defaoltBrush1);
}






void Monster::MonsterMove()
{
	center.y += speed * DELTA;
	if (center.y - radius >= SCREEN_HEIGHT)
	{
		isActive = false;
	}
}


