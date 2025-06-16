#include "framework.h"

Bullet::Bullet(float radius) : Circle(radius)
{
	
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
     if (!Bullet::GetActive()) { return; }
	 center.x += bulletSpeed;
	 if (center.x - radius > SCREEN_WIDTH)
	 {
	     isActive = false;
	 }
}

void Bullet::Fire(float2 pos)
{
	center = pos;
	isActive = true;
}

//void Bullet::Render(HDC hdc)
//{
//	Circle::Render(hdc);
//}




