#pragma once
#include "framework.h"

class SpawnPoint 
{	
public:
	SpawnPoint();
	SpawnPoint(Vector2 pos, float coolTime);
	~SpawnPoint();


	
	Vector2 center;
	int monsterIndexPool;
	float RespawnTime;
	float RespawnCurrentTime;
	bool SpawnActive;
	
};