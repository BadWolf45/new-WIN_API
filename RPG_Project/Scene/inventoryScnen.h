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



	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

	void Start() {}
	void End() {}

private:

};
