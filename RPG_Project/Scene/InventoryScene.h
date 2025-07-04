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



	// Scene��(��) ���� ��ӵ�
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
