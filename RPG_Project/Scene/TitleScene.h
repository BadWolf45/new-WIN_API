#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();


	// Scene��(��) ���� ��ӵ�
	void Update() override;

	void Render(HDC hdc) override;

private:
	Butten* startButten;
	Butten* exitButten;
};
