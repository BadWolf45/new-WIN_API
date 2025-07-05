#include "framework.h"

Rect::Rect()
{
}

Rect::Rect(Vector2 center, Vector2 size)
    : GameObject(center), size(size)
{
   
    fillColor = RGB(200, 200, 200);
    hFillBrush = CreateSolidBrush(fillColor);

   
}

Rect::~Rect()
{
    if (hFillBrush) DeleteObject(hFillBrush);
}

void Rect::Render(HDC hdc)
{
    if (!isActive)
    {
        return;
    }
    if (!hFillBrush) { return; }
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hFillBrush);

    Rectangle(hdc,
        center.x - size.x * 0.5f, center.y - size.y * 0.5f,
        center.x + size.x * 0.5f, center.y + size.y * 0.5f);

    SelectObject(hdc, hOldBrush);
}

void Rect::SetFillColor(COLORREF color)
{
    if (fillColor != color) 
    {
        fillColor = color;
       
        if (hFillBrush) DeleteObject(hFillBrush);
        hFillBrush = CreateSolidBrush(fillColor);
    }
}

bool Rect::isCollisionPoint(Vector2 point)
{

    float left = center.x - size.x * 0.5f;   
    float right = center.x + size.x * 0.5f;  
    float top = center.y - size.y * 0.5f;    
    float bottom = center.y + size.y * 0.5f;    
    bool isXInside = (point.x >= left) && (point.x <= right);   
    bool isYInside = (point.y >= top) && (point.y <= bottom);   
    return isXInside && isYInside;
}
