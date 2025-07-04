#include "framework.h"
#include "Scene/shootingScene.h"


GameManager::GameManager()
{
	hdc = GetDC(hWnd);
	Create();
	backBuffer = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBuffer, backBufferBitmap);

	SCENE->AddScene("Title", new TitleScene());
	SCENE->AddScene("Game", new ShootingScene());
	SCENE->AddScene("shop", new InventoryScene()); 
	
	SCENE->ChageScene("Title");
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);
	
	
	Relese();


	DeleteObject(backBufferBitmap);
	DeleteDC(backBuffer);

}

void GameManager::Update()
{
	Timer::GET()->Update();
	Input::GET()->Update();

	SCENE->Update();

}


void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	
	Timer::GET()->Render(backBuffer);
	SCENE->Render(backBuffer);

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::GET();
	Input::GET();
	SCENE;
}

void GameManager::Relese()
{
	Timer::Delete();
	Input::Delete();
	SceneManager::Delete();
}
