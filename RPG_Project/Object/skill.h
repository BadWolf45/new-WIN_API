#pragma once
#include"framework.h"
class Skill : public Circle
{
public:
	Skill(int radius);
	~Skill();

	void Update();
	void PowerShot(float2 pos);


};
