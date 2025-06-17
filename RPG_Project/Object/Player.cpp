#include "framework.h"

Player::Player(float radius) : Circle(radius)
{
    center = { 50,300 };
    //bulletManager = new BulletManager();
}

Player::~Player()
{
    //delete bulletManager;
  
}

void Player::Update()
{    
    MoveControl();	
}

void Player::Render(HDC hdc)
{
    MoveToEx(hdc, center.x, center.y - radius,nullptr);
    LineTo(hdc, center.x - radius, center.y + radius);
    MoveToEx(hdc, center.x - radius, center.y + radius,nullptr);
    LineTo(hdc, center.x + radius, center.y + radius);
    MoveToEx(hdc, center.x + radius, center.y + radius, nullptr);
    LineTo(hdc, center.x, center.y - radius);
    //Circle::Render(hdc);
    //bulletManager->Render(hdc);
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
            BulletManager::GET()->FireBullet(center);
        }      
    }
    else
    {
        iskeyPreesed = false;
    }
    BulletManager::GET()->Update();
}
