#pragma once
#include "framework.h"
class Rect : public GameObject
{
public:

	Rect();
	Rect(Vector2 center, Vector2 size);
	virtual ~Rect();

	void Render(HDC hdc);
	void SetFillColor(COLORREF color);

	bool isCollisionPoint(Vector2 point);

protected:
	Vector2 size;
	HBRUSH hFillBrush;
	COLORREF fillColor;
};
