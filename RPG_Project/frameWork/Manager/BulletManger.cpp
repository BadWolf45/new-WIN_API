#include "framework.h"



BulletManager::BulletManager()
{
    bullets.reserve(bulletPoolSize);
    for (int i = 0; i < bulletPoolSize; i++)
    {
        Bullet* bullet = new Bullet(5);
        bullet->SetActive(false);
        bullets.push_back(bullet);
    }

   
}

BulletManager::~BulletManager()
{
    for (Bullet* bullet : bullets)
    {
        delete bullet;
    }
    bullets.clear();
  
}

void BulletManager::Update()
{

    for (Bullet* bullet : bullets)
    {
        bullet->Update();            
    }
  

}

void BulletManager::Render(HDC hdc)
{
    for (Bullet* bullet : bullets)
    {
        if (bullet->GetActive())
            bullet->Render(hdc);
    }
   
}

void BulletManager::FireBullet(Vector2 pos, string tag, Vector2 direction)
{
    for (Bullet* bullet : bullets)
    {
        if (!bullet->GetActive())
        {

            bullet->Fire(pos,tag, direction);
            break;
        }
    }
}

bool BulletManager::IsCollision(Circle* circle, string tag)
{
    for (Bullet* bullet : bullets)
    {
        if (!bullet->GetActive())
            continue;
        if (bullet->GetTag() != tag)
            continue;
        if (!bullet->isColisionCircle(circle))
            continue;

        if (bullet->GetActive())
        {           
            bullet->SetActive(false);
            return true;
        }
    }
    return false;
}


