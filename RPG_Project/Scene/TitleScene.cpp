#include "framework.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (Input::GET()->IsKeyDown(VK_F1))
	{
		SCENE->ChageScene("Game");
	}
}

void TitleScene::Render(HDC hdc)
{
	TextOut(hdc, 100, 100, L"TitleScene", 12);
}
