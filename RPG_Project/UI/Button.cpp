#include "framework.h"
#include "Button.h"

Button::Button(Vector2 center, Vector2 size)
	: Rect(center,size)
{

}

Button::~Button()
{


}

void Button::Update()
{
    bool isMouseOver = isColisionPoint(mousePos);
    bool currentLButtonDown = GetAsyncKeyState(VK_LBUTTON) & 0x8000;

    if (isMouseOver)
    {
        if (currentLButtonDown)
        {
            currentState = ButtonState::DOWN;
        }
        else
        {
            if (currentState == ButtonState::DOWN && !currentLButtonDown && prevLButtonDownState)
            {
                if (onClick)
                {
                    onClick();
                }
            }
            currentState = ButtonState::OVER;
        }
    }
    else
        currentState = ButtonState::NORMAL;

    prevLButtonDownState = currentLButtonDown;
}

void Button::Render(HDC hdc)
{
	if (!isActive)
		return;
    COLORREF targetColor;
    switch (currentState)
    {
    case ButtonState::NORMAL:
        targetColor = RGB(200, 200, 200); 
        break;
    case ButtonState::OVER:
        targetColor = RGB(150, 150, 255); 
        break;
    case ButtonState::DOWN:
        targetColor = RGB(100, 100, 200); 
        break;
    }
    SetFillcolor(targetColor); 
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
