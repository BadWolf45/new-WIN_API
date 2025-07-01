#pragma once
#include "framework.h"

class Butten : public Rect
{
public:

	Butten(Vector2 center, Vector2 size);
	~Butten();

	enum class ButtenState
	{
		NORMAL,
		OVER,
		DOWN
	};

	void Update();
	void Render(HDC hdc);

	void SetText(wstring text) { this->text = text; }

private:
	wstring text = L"Butten";
	HBRUSH nomalBrush;
	HBRUSH overBrush;
	HBRUSH downBrush;
	ButtenState state = ButtenState::NORMAL;
};
