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
	if (Input::GET()->IsKeyDown(VK_F2))
	{
		SCENE->ChageScene("Title");
	}
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
	MonsterManager::GET()->SetPlayer(player);
	BulletManager::GET();
}

void ShootingScene::End()
{
	delete player;
	MonsterManager::GET()->Delete;
	BulletManager::GET()->Delete;
}
