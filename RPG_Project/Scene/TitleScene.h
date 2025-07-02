#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();


	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

	void GameStart();
	void GameEXIT();
	void Font(HDC hdc);

private:
	Button* startButton;
	Button* exitButton;

};
