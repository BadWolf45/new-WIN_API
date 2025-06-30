#include "framework.h"
#include "Butten.h"

Butten::Butten(Vector2 center, Vector2 size)
	: Rect(center,size)
{
}

Butten::~Butten()
{
}

void Butten::Update()
{
}

void Butten::Render(HDC hdc)
{
	if (!isActive)
		return;

	TextOut(hdc,
		center.x - size.x * 0.5f, center.y - size.y * 0.5f,
		text.c_str(), text.length());
}
