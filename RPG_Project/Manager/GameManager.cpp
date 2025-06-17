#include "framework.h"
#include "GameManager.h"

GameManager::GameManager()
{
	
	player = new Player(60);
	//monster = new Monster(30);
	monster
	BulletManager::GET();

	hdc = GetDC(hWnd);

	backBuffer = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBuffer, backBufferBitmap);
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);
	
	delete player;
	delete monster;
	BulletManager::GET()->Delete;

	DeleteObject(backBufferBitmap);
	DeleteDC(backBuffer);
}

void GameManager::Update()
{
	player->Update();
	//BulletManager::GET()->Update();
	monster->Update();

	//InvalidateRect(hWnd, nullptr, false);
	
}


void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	
	BulletManager::GET()->Render(backBuffer);
	player->Render(backBuffer);
	monster->Render(backBuffer);
	

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}
