#include "framework.h"
#include "Scene/shootingScene.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);
	scene = new ShootingScene();
	Create();
	backBuffer = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBuffer, backBufferBitmap);
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);
	
	delete scene;
	Relese();


	DeleteObject(backBufferBitmap);
	DeleteDC(backBuffer);
}

void GameManager::Update()
{
	Timer::GET()->Update();
	Input::GET()->Update();

	scene->Update();

}


void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	
	Timer::GET()->Render(backBuffer);
	scene->Render(backBuffer);

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::GET();
	Input::GET();
}

void GameManager::Relese()
{
	Timer::Delete();
	Input::Delete();
}
