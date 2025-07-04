#include "framework.h"


Player::Player(float radius) : Circle(radius)
{
    center = { SCREEN_WIDTH>>1,SCREEN_HEIGHT * 4/5 };
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
   gaugeUpdate();
   aiming();

   if (BulletManager::GET()->IsCollision(this, "monster"))
   {
       isActive = false;
   }
 
}

void Player::Render(HDC hdc)
{
    DrawLine(hdc);
    gauge(hdc);

    MoveToEx(hdc, firePos.x, firePos.y, nullptr);
    LineTo(hdc, aimPoint.x, aimPoint.y);
   
}



void Player::MoveControl()
{
    KeybordMove();
   

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

    gauge::GET()->SetCenter(center.x , center.y +radius + 10);
    
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

void Player::gauge(HDC hdc)
{
  


    if (isCharging || currentCharge > 0.0f) 
    {
        float gaugeWidth = 60.0f; 
        float gaugeHeight = 7.0f; 

        // 게이지 위치 계산
        float gaugeX = center.x - gaugeWidth / 2.0f;
        float gaugeY = center.y + radius + 5.0f;

        
        RECT gaugeBackgroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + gaugeWidth), (int)(gaugeY + gaugeHeight) };

        
        HBRUSH hGrayBrush = CreateSolidBrush(RGB(100, 100, 100)); 
        FillRect(hdc, &gaugeBackgroundRect, hGrayBrush); 
        DeleteObject(hGrayBrush); 

    
        float chargeRatio = currentCharge / maxCharge;
        chargeRatio = max(0.0f, std::min(chargeRatio, 1.0f));

        
        float currentGaugeWidth = gaugeWidth * chargeRatio;

     
        RECT gaugeForegroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + currentGaugeWidth), (int)(gaugeY + gaugeHeight) };

        HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0)); // 노란색 브러시 생성
        FillRect(hdc, &gaugeForegroundRect, hYellowBrush); // 전경 사각형 채우기
        DeleteObject(hYellowBrush); // 브러시 삭제

      
    }


  
}

void Player::gaugeUpdate()
{
   
    if (GetAsyncKeyState(VK_SHIFT)) // 
    {
        isCharging = true;
        currentCharge += chargeSpeed;
        currentCharge = min(currentCharge, maxCharge);
    }
    else 
    {
        if (isCharging)
        {
            // TODO: 강력한 공격 발동!
            // currentCharge 값을 사용해서 공격의 위력을 결정!
            // 예: LaunchPowerfulAttack(currentCharge);

            // 공격 발동 후 기 모으는 상태 리셋
            isCharging = false;
            currentCharge = 0.0f; // 모은 기 초기화

            // TODO: 캐릭터 움직임 속도 원래대로 복원
            // speedMultiplier = 1.0f; // 예시
        }
        // 기 모으는 키를 누르지 않고 있을 때는 isCharging이 false 상태 유지
        // currentCharge는 공격 발동 시 0으로 리셋되거나, 시간이 지나면 자연 감소하게 만들 수도 있음
    }
}

void Player::KeybordMove()
{
    if (GetAsyncKeyState('D'))
    {
        //center.x += speed;
        center += Vector2::Right() * speed * DELTA;
    }
    if (GetAsyncKeyState('A'))
    {
        center += Vector2::Left() * speed * DELTA;
    }
    if (GetAsyncKeyState('W'))
    {
        center += Vector2::Up() * speed * DELTA;
    }
    if (GetAsyncKeyState('S'))
    {
        center += Vector2::Down() * speed * DELTA;
    }
    if (Input::GET()->IsKeyDown(VK_SPACE))
    {
        Vector2 direction = aimPoint - firePos;
        BulletManager::GET()->FireBullet(firePos, "player", direction.GetNomalize());
    }
    if (Input::GET()->IsKeyPress(VK_RIGHT))
    {
        angle -= DELTA;
    }

    if (Input::GET()->IsKeyPress(VK_LEFT))
    {
        angle += DELTA;
    }
}

void Player::MouseControl()
{

}

void Player::aiming()
{

   // Vector2 direction = mousePos - firePos;
   // aimPoint = firePos + direction.GetNomalize() * aimLenght;

    float x = cos(angle) * aimLenght;
    float y = -sin(angle) * aimLenght;

    aimPoint = firePos + Vector2(x, y);
}
