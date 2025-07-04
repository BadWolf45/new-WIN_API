#pragma once
#include "framework.h"

class HealthPointBar : public Rect
{
public:
	HealthPointBar();
	HealthPointBar(Vector2 center,Vector2 size, int HP);
	
	~HealthPointBar();

private:

	int HealthPoint;
	
};
