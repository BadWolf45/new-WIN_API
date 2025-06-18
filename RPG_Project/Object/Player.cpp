#include "framework.h"

Player* Player::instance = nullptr;
Player::Player(float radius) : Circle(radius)
{
    center = { SCREEN_WIDTH>>1,SCREEN_HEIGHT -100 };
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
}

Player::~Player()
{ 
    DeleteObject(hPen);
}

void Player::Update()  
{    
   MoveControl();
   LineOut();
}

void Player::Render(HDC hdc)
{
    DrawLine(hdc);
}



void Player::MoveControl()
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        center.x += speed;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        center.x -= speed;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        center.y -= speed;        
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        center.y += speed;
    }    
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!iskeyPreesed)
        {
            iskeyPreesed = true;
            BulletManager::GET()->FireBullet(firePos, 100);
        }      
    }
    else
    {
        iskeyPreesed = false;
    }
    BulletManager::GET()->Update();
}

void Player::LineOut()
{
    if (center.x - radius <= 0)
    {
        center.x = radius;
    }
    if (center.x + radius >= SCREEN_WIDTH)
    {
        center.x = SCREEN_WIDTH - radius;
    }
    if (center.y - radius <= 0)
    {
        center.y = radius;
    }
    if (center.y + radius >= SCREEN_HEIGHT)
    {
        center.y = SCREEN_HEIGHT - radius;
    }
}

void Player::DrawLine(HDC hdc)
{
    firePos = { center.x, center.y - radius };
    HPEN defaultPen = (HPEN)SelectObject(hdc, hPen);
    MoveToEx(hdc, firePos.x, firePos.y, nullptr);
    LineTo(hdc, center.x - radius + 5, center.y + radius);

    MoveToEx(hdc, center.x - radius + 5, center.y + radius, nullptr);
    LineTo(hdc, center.x, center.y + 10);

    MoveToEx(hdc, center.x, center.y + 10, nullptr);
    LineTo(hdc, center.x + radius - 5, center.y + radius);

    MoveToEx(hdc, center.x + radius - 5, center.y + radius, nullptr);
    LineTo(hdc, firePos.x, firePos.y);

    SelectObject(hdc, defaultPen);
}
