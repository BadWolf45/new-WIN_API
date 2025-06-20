#pragma once
#include "framework.h"

class gauge : public Singleton<gauge>
{
	friend class Singleton;
	
private:
	gauge();
	~gauge();

public:

	void Update();
	void Render(HDC hdc);

	void SetCenter(float2 center) { center = center; }
	void SetCenter(float x, float y) { center.x = x, center.y = y; }
	float2 GetCenter() { return center; }
private:
	float2 center = {};
	int maxCharge;
	int currentCharge;
	int chargeSpeed;
	bool isCharging;
};
