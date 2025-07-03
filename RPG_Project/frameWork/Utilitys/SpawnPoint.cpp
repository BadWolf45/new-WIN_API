#include "framework.h"

SpawnPoint::SpawnPoint()
{
}

SpawnPoint::SpawnPoint(Vector2 pos, float coolTime)
	:center(pos), RespawnTime(coolTime), RespawnCurrentTime(0.0f), SpawnActive(false),monsterIndexPool(-1)
{
}

SpawnPoint::~SpawnPoint()
{
}

