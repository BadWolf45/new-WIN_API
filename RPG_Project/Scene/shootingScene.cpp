#include "framework.h"

ShootingScene::ShootingScene()
{
}

ShootingScene::~ShootingScene()
{	
}

void ShootingScene::Update()
{
	player->Update();
	MonsterManager::GET()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);
	MonsterManager::GET()->Render(hdc);
	BulletManager::GET()->Render(hdc);
}


void ShootingScene::Start()
{
	player = new Player(20);	
	BulletManager::GET();
	MonsterManager::GET()->SetPlayer(player);
}

void ShootingScene::End()
{
	delete player;
	BulletManager::Delete();
	MonsterManager::Delete();	
}
