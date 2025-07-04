#pragma once
#include "framework.h"

class InventoryScene : public Scene
{

public:

	enum class ShopState
	{
		shop,
		inventory,
		exit
	};

	InventoryScene();
	~InventoryScene();



	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

	void CreateButton();

	void SceneBack();

	void Start() {}
	void End() {}

private:

	//Button* shop;
	//Button* inventory;
	Button* back;

	Rect* rect;

};
