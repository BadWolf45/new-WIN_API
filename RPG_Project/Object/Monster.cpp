#include "framework.h"
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
	Damage();
	//Fire();

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
	//center.y += speed * DELTA;
	//if (center.y - radius >= SCREEN_HEIGHT)
	//{
	//	isActive = false;
	//}

	// 플레이어 객체가 유효한지 먼저 확인 (널 포인터 참조 방지)
	if (player == nullptr) {
		return; // 플레이어가 없으면 움직이지 않음
	}

	// 몬스터의 현재 위치에서 플레이어의 위치까지의 방향 벡터 계산
	Vector2 direction = player->GetCenter() - center;

	// 방향 벡터를 정규화 (크기를 1로 만듦)
	// GetNomalize() 함수가 Vector2 클래스에 정의되어 있다고 가정
	direction = direction.GetNomalize();

	// 정규화된 방향 벡터에 속도와 DELTA(시간)를 곱하여 이동량 계산
	center.x += direction.x * speed * DELTA;
	center.y += direction.y * speed * DELTA;

	// (선택 사항) 화면 밖으로 나가는 경우 처리 (현재는 플레이어를 따라가므로 필요 없을 수 있음)
	// if (center.y - radius >= SCREEN_HEIGHT)
	// {
	//     isActive = false;
	// }
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




