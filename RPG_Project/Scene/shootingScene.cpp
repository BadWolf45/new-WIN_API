#include "framework.h"

ShootingScene::ShootingScene()
{
	Player::Get();
	MonsterManager::GET()->SetPlayer(Player::Get());
	BulletManager::GET();

}

ShootingScene::~ShootingScene()
{
	Player::Get()->Delete();
	MonsterManager::GET()->Delete;
	BulletManager::GET()->Delete;
}

void ShootingScene::Update()
{
	Player::Get()->Update();
	MonsterManager::GET()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	BulletManager::GET()->Render(hdc);
	Player::Get()->Render(hdc);
	MonsterManager::GET()->Render(hdc);
	
}
