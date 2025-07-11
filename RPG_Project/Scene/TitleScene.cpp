#include "framework.h"

TitleScene::TitleScene()
{
	startButton = new Button(Vector2(SCREEN_WIDTH * 0.5, 350), Vector2(200, 90));
	startButton->SetText(L"start");
	startButton->SetOnClickListener([this]() {this->GameStart(); });

	shop = new Button(Vector2(SCREEN_WIDTH * 0.5, 450), Vector2(200,90));
	shop->SetText(L"shop");
	shop->SetOnClickListener([this]() {this->GameShop(); });

	exitButton = new Button(Vector2(SCREEN_WIDTH * 0.5, 550), Vector2(200, 90));
	exitButton->SetText(L"EXIT");
	exitButton->SetOnClickListener([this]() {this->GameEXIT();});


	
}

TitleScene::~TitleScene()
{
	delete startButton;
	delete exitButton;
	delete shop;
}

void TitleScene::Update()
{
	startButton->Update();
	exitButton->Update();
	//shop->Update();
}

void TitleScene::Render(HDC hdc)
{
	//Font(hdc);
	//HFONT hFont = CreateFont(
	//	50,                 // cHeight: 폰트 높이 (픽셀)
	//	0,                  // cWidth: 너비 (0이면 비율에 맞게 자동 조절)
	//	0,                  // cEscapement: 기울기 각도
	//	0,                  // cOrientation: 각 문자 기울기 각도
	//	FW_BOLD,            // cWeight: 굵기 (700은 굵게)
	//	FALSE,              // bItalic: 이탤릭체 아님
	//	FALSE,              // bUnderline: 밑줄 없음
	//	FALSE,              // bStrikeOut: 취소선 없음
	//	DEFAULT_CHARSET,    // iCharSet: 기본 문자셋
	//	OUT_DEFAULT_PRECIS, // 출력 정밀도
	//	CLIP_DEFAULT_PRECIS,// 클리핑 정밀도
	//	ANTIALIASED_QUALITY,// iQuality: 출력 품질 (부드러운 글꼴)
	//	DEFAULT_PITCH | FF_SWISS, // iPitchAndFamily: 폰트 피치 및 패밀리
	//	L"Arial"            // pszFaceName: 폰트 이름 (예: "Arial", "굴림", "맑은 고딕")
	//);
	//
	// TODO: DC에 폰트 선택! (이전 폰트 저장)
	//HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
	wstring TitleText = L"TitleScene";
	TextOut(hdc, 100, 100, TitleText.c_str(), TitleText.length());

	//SelectObject(hdc, hOldFont);
	startButton->Render(hdc);
	exitButton->Render(hdc);
	//shop->Render(hdc);
}

void TitleScene::GameStart()
{
	SCENE->ChageScene("Game");
}

void TitleScene::GameEXIT()
{
	PostQuitMessage(0);
}

void TitleScene::GameShop()
{
	SCENE->ChageScene("shop");
}

void TitleScene::Font(HDC hdc)
{

}
