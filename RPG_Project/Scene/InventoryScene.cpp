#include "framework.h"

InventoryScene::InventoryScene()
{
	CreateButton();
	rect = new Rect(Vector2(300,500),Vector2(200,500));

}

InventoryScene::~InventoryScene()
{
	delete back;
	delete rect;
}

void InventoryScene::Update()
{
	back->Update();
	
}

void InventoryScene::Render(HDC hdc)
{
	back->Render(hdc);
	rect->Render(hdc);
}

void InventoryScene::CreateButton()
{
	back = new Button(Vector2(100, 100), Vector2(100, 50));
	back->SetText(L"뒤로가기");
	back->SetOnClickListener([this]() {this->SceneBack(); });
}

void InventoryScene::SceneBack()
{
	SCENE->ChageScene("Title");
}
