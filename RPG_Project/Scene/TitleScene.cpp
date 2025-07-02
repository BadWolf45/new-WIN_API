#include "framework.h"

TitleScene::TitleScene()
{
	startButten = new Butten(Vector2(300, 400), Vector2(200, 90));
	startButten->SetText(L"start");
	startButten->SetOnClickListener([this]() {this->GameStart(); });

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
	startButten->Update();
	exitButten->Update();
}

void TitleScene::Render(HDC hdc)
{
	Font(hdc);
	HFONT hFont = CreateFont(
		50,                 // cHeight: ��Ʈ ���� (�ȼ�)
		0,                  // cWidth: �ʺ� (0�̸� ������ �°� �ڵ� ����)
		0,                  // cEscapement: ���� ����
		0,                  // cOrientation: �� ���� ���� ����
		FW_BOLD,            // cWeight: ���� (700�� ����)
		FALSE,              // bItalic: ���Ÿ�ü �ƴ�
		FALSE,              // bUnderline: ���� ����
		FALSE,              // bStrikeOut: ��Ҽ� ����
		DEFAULT_CHARSET,    // iCharSet: �⺻ ���ڼ�
		OUT_DEFAULT_PRECIS, // ��� ���е�
		CLIP_DEFAULT_PRECIS,// Ŭ���� ���е�
		ANTIALIASED_QUALITY,// iQuality: ��� ǰ�� (�ε巯�� �۲�)
		DEFAULT_PITCH | FF_SWISS, // iPitchAndFamily: ��Ʈ ��ġ �� �йи�
		L"Arial"            // pszFaceName: ��Ʈ �̸� (��: "Arial", "����", "���� ���")
	);

	// TODO: DC�� ��Ʈ ����! (���� ��Ʈ ����)
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
	wstring TitleText = L"TitleScene";
	TextOut(hdc, 100, 100, TitleText.c_str(), TitleText.length());

	SelectObject(hdc, hOldFont);
	startButten->Render(hdc);
	exitButten->Render(hdc);
}

void TitleScene::GameStart()
{
	SCENE->ChageScene("Game");
}

void TitleScene::GameEXIT()
{
	PostQuitMessage(0);
}

void TitleScene::Font(HDC hdc)
{

}
