#include "framework.h"

Player* Player::instance = nullptr;
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
    if (Input::GET()->IsKeyDown(VK_LBUTTON))
    {
        Vector2 direction = mousePos - firePos;
        BulletManager::GET()->FireBullet(firePos, "player", direction.GetNomalize());
    }
    if (Input::GET()->IsKeyPress('E'))
    {
        angle -= DELTA;
    }

    if (Input::GET()->IsKeyPress('Q'))
    {
        angle += DELTA;
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
    // TODO: 체력바 그리기 코드 ...

// TODO: 기 모으는 게이지 그리기!
// 기를 모으고 있을 때만 게이지를 보여주는 게 좋겠지?
    if (isCharging || currentCharge > 0.0f) // 기 모으는 중이거나 모은 기가 있을 때
    {
        float gaugeWidth = 60.0f; // 게이지 전체 너비 (예시)
        float gaugeHeight = 7.0f; // 게이지 높이 (예시)

        // 게이지 위치 계산 (캐릭터 중심 아래쪽으로)
        float gaugeX = center.x - gaugeWidth / 2.0f;
        float gaugeY = center.y + radius + 5.0f;

        // 게이지 사각형 영역 (정수 좌표로 변환)
        RECT gaugeBackgroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + gaugeWidth), (int)(gaugeY + gaugeHeight) };

        // 1. 배경 막대 그리기 (회색)
        HBRUSH hGrayBrush = CreateSolidBrush(RGB(100, 100, 100)); // 회색 브러시 생성
        FillRect(hdc, &gaugeBackgroundRect, hGrayBrush); // 배경 사각형 채우기
        DeleteObject(hGrayBrush); // 브러시 삭제

        // 2. 현재 기 모은 비율 계산
        float chargeRatio = currentCharge / maxCharge;
        // 비율이 0.0 ~ 1.0 범위를 벗어나지 않도록 클램핑
        chargeRatio = max(0.0f, std::min(chargeRatio, 1.0f));

        // 3. 현재 기 게이지 막대 너비 계산
        float currentGaugeWidth = gaugeWidth * chargeRatio;

        // 4. 전경 막대 그리기 (노란색)
        // 현재 기 게이지 막대 사각형 영역 (정수 좌표로 변환)
        RECT gaugeForegroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + currentGaugeWidth), (int)(gaugeY + gaugeHeight) };

        HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0)); // 노란색 브러시 생성
        FillRect(hdc, &gaugeForegroundRect, hYellowBrush); // 전경 사각형 채우기
        DeleteObject(hYellowBrush); // 브러시 삭제

        // TODO: 필요하다면 게이지 테두리 그리기 (Rectangle 함수 사용)
    }


  
}

void Player::gaugeUpdate()
{
    // TODO: 발사 타이머 업데이트 (총알 딜레이 시 필요) ...
// fireTimer += 1.0f;

   // MoveControl(); // 캐릭터 움직임 제어 (여기서 키 입력 확인)

   
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

void Player::aiming()
{

   // Vector2 direction = mousePos - firePos;
   // aimPoint = firePos + direction.GetNomalize() * aimLenght;

    float x = cos(angle) * aimLenght;
    float y = -sin(angle) * aimLenght;

    aimPoint = firePos + Vector2(x, y);
}
