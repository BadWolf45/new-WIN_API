#include "framework.h"
#include "monster.h"

Monster::Monster(float radius) : Circle(radius)
{
	
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hbluebrush = CreateSolidBrush(RGB(0, 0, 255));

	//HPBar = new HealthPointBar(Vector2(this->center.x, this->center.y + 100),Vector2(100,50));
	HPBar = new HealthPointBar(Vector2(this->center), Vector2(40, 10), healthPoint);
	
	
}

Monster::~Monster()
{
	DeleteObject(hRedBrush);
	DeleteObject(hbluebrush);
	delete HPBar;
	
}

void Monster::Update()
{
	if (!isActive) { return; }
	MonsterMove();
	Damage();
	//Fire();
	

}

void Monster::Render(HDC hdc)
{
	if (!isActive) { return; }
	HBRUSH defaoltBrush1 =  (HBRUSH)SelectObject(hdc, hselectBrush);
	Circle::Render(hdc);
	float Low = center.y + radius;
	HPBar->SetCenter(center.x, Low + 10);

	SelectObject(hdc, defaoltBrush1);

	HPBar->Render(hdc);
}






void Monster::MonsterMove()
{
	//center.y += speed * DELTA;
	//if (center.y - radius >= SCREEN_HEIGHT)
	//{
	//	isActive = false;
	//}

	
	if (player == nullptr) {
		return; 
	}
	Vector2 direction = player->GetCenter() - center;		
	direction = direction.GetNomalize();	
	center.x += direction.x * speed * DELTA;
	center.y += direction.y * speed * DELTA;
}

void Monster::Damage()
{
	if (isColisionPoint(mousePos))
	{
		hselectBrush = hRedBrush;
	}
	else
	{
		hselectBrush = hbluebrush;
	}

	if (BulletManager::GET()->IsCollision(this,"player"))
	{
		
		healthPoint -= 2;
		if (healthPoint <= 0)
		{
			isActive = false;
			MonsterManager::GET()->NotifyMonsterDeath(this);
		}
	}
}

void Monster::Fire()
{
	fireTime += DELTA;
	if (fireTime >= fireinter)
	{
		
		fireTime = 0.0f;

		//MultiShot();
		Vector2 direction = player->GetCenter() - center;
		BulletManager::GET()->FireBullet(center, "monster", direction.GetNomalize());

	}

}

void Monster::MultiShot()
{
	float stepAngle = PI * 2.0f / fireCount;
	for (int i = 0; i < fireCount; i++)
	{
		angle = stepAngle * i;
		Vector2 direction(cos(angle), sin(angle));
		BulletManager::GET()->FireBullet(center, "monster", direction.GetNomalize());
	}

}




