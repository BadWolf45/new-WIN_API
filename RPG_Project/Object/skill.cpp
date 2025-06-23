#include "framework.h"

Skill::Skill(int radius) : Circle(radius)
{
	isActive = false;
}

Skill::~Skill() 
{
}

void Skill::Update()
{
	center.y -= 0.05;

}