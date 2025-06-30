#pragma once
#include "framework.h"
class Rect : public GameObject
{
public:

	Rect();
	Rect(Vector2 center, Vector2 size);
	~Rect();

	void Render(HDC hdc);

	bool isColisionPoint(Vector2 point);

protected:
	Vector2 size;
};
