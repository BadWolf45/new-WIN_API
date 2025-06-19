#include "framework.h"
#include "Scene/shootingScene.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);
	scene = new ShootingScene();
	backBuffer = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBuffer, backBufferBitmap);
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);
	
	delete scene;

	DeleteObject(backBufferBitmap);
	DeleteDC(backBuffer);
}

void GameManager::Update()
{
	scene->Update();

}


void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	

	scene->Render(backBuffer);

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}
