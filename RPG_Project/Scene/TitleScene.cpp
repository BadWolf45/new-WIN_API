#include "framework.h"

TitleScene::TitleScene()
{
	startButten = new Butten(Vector2(300, 400), Vector2(200, 90));
	startButten->SetText(L"start");

	exitButten = new Butten(Vector2(300, 500), Vector2(200, 90));
	exitButten->SetText(L"EXIT");
}

TitleScene::~TitleScene()
{
	delete startButten;
	delete exitButten;
}

void TitleScene::Update()
{
	if (Input::GET()->IsKeyDown(VK_F1))
	{
		SCENE->ChageScene("Game");
	}

	startButten->Update();
	exitButten->Update();
}

void TitleScene::Render(HDC hdc)
{
	TextOut(hdc, 100, 100, L"TitleScene", 12);

	startButten->Render(hdc);
	exitButten->Render(hdc);
}
