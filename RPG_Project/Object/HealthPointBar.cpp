#include "framework.h"
#include "HealthPointBar.h"

HealthPointBar::HealthPointBar()
{
	
}

HealthPointBar::HealthPointBar(Vector2 center, Vector2 size, int HP)
	: Rect(center,size) , HealthPoint(HP)
{

}

HealthPointBar::~HealthPointBar()
{
}
