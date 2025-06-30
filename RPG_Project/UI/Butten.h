#pragma once
#include "framework.h"

class Butten : public Rect
{
public:

	Butten(Vector2 center, Vector2 size);
	~Butten();

	void Update();
	void Render(HDC hdc);


private:
	wstring text = L"Butten";


};
