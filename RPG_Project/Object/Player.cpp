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
    // TODO: ü�¹� �׸��� �ڵ� ...

// TODO: �� ������ ������ �׸���!
// �⸦ ������ ���� ���� �������� �����ִ� �� ������?
    if (isCharging || currentCharge > 0.0f) // �� ������ ���̰ų� ���� �Ⱑ ���� ��
    {
        float gaugeWidth = 60.0f; // ������ ��ü �ʺ� (����)
        float gaugeHeight = 7.0f; // ������ ���� (����)

        // ������ ��ġ ��� (ĳ���� �߽� �Ʒ�������)
        float gaugeX = center.x - gaugeWidth / 2.0f;
        float gaugeY = center.y + radius + 5.0f;

        // ������ �簢�� ���� (���� ��ǥ�� ��ȯ)
        RECT gaugeBackgroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + gaugeWidth), (int)(gaugeY + gaugeHeight) };

        // 1. ��� ���� �׸��� (ȸ��)
        HBRUSH hGrayBrush = CreateSolidBrush(RGB(100, 100, 100)); // ȸ�� �귯�� ����
        FillRect(hdc, &gaugeBackgroundRect, hGrayBrush); // ��� �簢�� ä���
        DeleteObject(hGrayBrush); // �귯�� ����

        // 2. ���� �� ���� ���� ���
        float chargeRatio = currentCharge / maxCharge;
        // ������ 0.0 ~ 1.0 ������ ����� �ʵ��� Ŭ����
        chargeRatio = max(0.0f, std::min(chargeRatio, 1.0f));

        // 3. ���� �� ������ ���� �ʺ� ���
        float currentGaugeWidth = gaugeWidth * chargeRatio;

        // 4. ���� ���� �׸��� (�����)
        // ���� �� ������ ���� �簢�� ���� (���� ��ǥ�� ��ȯ)
        RECT gaugeForegroundRect = { (int)gaugeX, (int)gaugeY, (int)(gaugeX + currentGaugeWidth), (int)(gaugeY + gaugeHeight) };

        HBRUSH hYellowBrush = CreateSolidBrush(RGB(255, 255, 0)); // ����� �귯�� ����
        FillRect(hdc, &gaugeForegroundRect, hYellowBrush); // ���� �簢�� ä���
        DeleteObject(hYellowBrush); // �귯�� ����

        // TODO: �ʿ��ϴٸ� ������ �׵θ� �׸��� (Rectangle �Լ� ���)
    }


  
}

void Player::gaugeUpdate()
{
    // TODO: �߻� Ÿ�̸� ������Ʈ (�Ѿ� ������ �� �ʿ�) ...
// fireTimer += 1.0f;

   // MoveControl(); // ĳ���� ������ ���� (���⼭ Ű �Է� Ȯ��)

   
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
            // TODO: ������ ���� �ߵ�!
            // currentCharge ���� ����ؼ� ������ ������ ����!
            // ��: LaunchPowerfulAttack(currentCharge);

            // ���� �ߵ� �� �� ������ ���� ����
            isCharging = false;
            currentCharge = 0.0f; // ���� �� �ʱ�ȭ

            // TODO: ĳ���� ������ �ӵ� ������� ����
            // speedMultiplier = 1.0f; // ����
        }
        // �� ������ Ű�� ������ �ʰ� ���� ���� isCharging�� false ���� ����
        // currentCharge�� ���� �ߵ� �� 0���� ���µǰų�, �ð��� ������ �ڿ� �����ϰ� ���� ���� ����
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
