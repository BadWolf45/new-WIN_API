#pragma once
#include "framework.h"

class inventoryScnen : public Scene
{

public:

	enum class State
	{
		shop,
		inventory,
		exit
	};

	inventoryScnen();
	~inventoryScnen();



	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;

	void Start() {}
	void End() {}

private:

};
