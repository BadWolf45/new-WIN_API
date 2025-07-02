#include "framework.h"

ShootingScene::ShootingScene()
{
	mainButton = new Button(Vector2(SCREEN_WIDTH - 200, 150), Vector2(150, 50));
	mainButton->SetText(L"main menu");
	mainButton->SetOnClickListener([this]() {this->MainMenu();});
}

ShootingScene::~ShootingScene()
{	
	delete mainButton;
}

void ShootingScene::Update()
{
	player->Update();
	MonsterManager::GET()->Update();
	mainButton->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);
	MonsterManager::GET()->Render(hdc);
	BulletManager::GET()->Render(hdc);
	mainButton->Render(hdc);
}

void ShootingScene::MainMenu()
{
	SCENE->ChageScene("Title");
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
