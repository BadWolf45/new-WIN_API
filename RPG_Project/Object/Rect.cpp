#include "framework.h"

Rect::Rect()
{
}

Rect::Rect(Vector2 center, Vector2 size)
    : GameObject(center), size(size)
{
}

Rect::~Rect()
{
}

void Rect::Render(HDC hdc)
{
    if (!isActive)
    {
        return;
    }

    Rectangle(hdc,
        center.x - size.x * 0.5f, center.y - size.y * 0.5f,
        center.x + size.x * 0.5f, center.y + size.y * 0.5f);
}

bool Rect::isColisionPoint(Vector2 point)
{
    return false;
}
