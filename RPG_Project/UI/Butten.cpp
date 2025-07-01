#include "framework.h"
#include "Butten.h"

Butten::Butten(Vector2 center, Vector2 size)
	: Rect(center,size)
{
    nomalBrush = CreateSolidBrush(RGB(255, 0, 0));
    overBrush = CreateSolidBrush(RGB(255, 255, 0));
    downBrush = CreateSolidBrush(RGB(0, 255, 0));
}

Butten::~Butten()
{
	delete nomalBrush;
	delete overBrush;
	delete downBrush;

}

void Butten::Update()
{
}

void Butten::Render(HDC hdc)
{
	if (!isActive)
		return;
    HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, nomalBrush);
	Rect::Render(hdc);
    int oldBkMode = SetBkMode(hdc, TRANSPARENT);

    RECT textRect = {
          (int)(center.x - size.x * 0.5f), 
          (int)(center.y - size.y * 0.5f), 
          (int)(center.x + size.x * 0.5f), 
          (int)(center.y + size.y * 0.5f)  
    };


    DrawText(hdc,
        text.c_str(),text.length(), &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
	SelectObject(hdc, defaultBrush);
}
