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
	 center += direction * bulletSpeed * DELTA;
	 
	 if (center.y + radius < 0)
	 {
	     isActive = false;
	 }
	 if (center.y - radius > SCREEN_HEIGHT)
	 {
		 isActive = false;
	 }
	 if (center.x + radius < 0)
	 {
		 isActive = false;
	 }
	 if (center.x - radius > SCREEN_WIDTH)
	 {
		 isActive = false;
	 }
}



void Bullet::Fire(Vector2 pos, string tag, Vector2 direction)
{
	this->direction = direction;
	this->tag = tag;
	center = pos;
	isActive = true;
}

//void Bullet::Render(HDC hdc)
//{
//	Circle::Render(hdc);
//}




