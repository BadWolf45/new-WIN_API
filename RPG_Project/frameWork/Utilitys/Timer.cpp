#include "framework.h"


Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&preriodFrequency); // 1�ʵ��� CPU �� �������� ��ȯ�ϴ� �Լ�
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime); // ���� cpu�� �������� ��ȯ�ϴ� �Լ�.
	timeScale = 1.0f / preriodFrequency;
	
	
}

Timer::~Timer()
{

}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	elapsedTime = (float)(currentTime - lastTime) / preriodFrequency;
	lastTime = currentTime;
	frameCount++;
	oneSecondCount += elapsedTime;
	if (oneSecondCount >= 1.0f)
	{
		frameRate = frameCount;
		frameCount = 0;
		oneSecondCount = 0.0f;
	}
	timeScale = elapsedTime * deltaScale;
}

void Timer::Render(HDC hdc)
{
	wstring str = L"FPS : " + to_wstring(frameRate);
	TextOut(hdc, 0, 0, str.c_str(), str.size());
	str = L"Elapsed Time : " + to_wstring(elapsedTime);
	TextOut(hdc, 0, 20, str.c_str(), str.size());
}
