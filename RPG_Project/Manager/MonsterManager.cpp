#include "framework.h"
#include "MonsterManager.h"

MonsterManager* MonsterManager::instance = nullptr;

MonsterManager::MonsterManager()
{
	MonsterPoolcreate();
}

MonsterManager::~MonsterManager()
{
	MonsterPoolDelete();
}

void MonsterManager::Update()
{
	spawnTimer += DELTA;
	if (spawnTimer >= spawnDelay)
	{
		spawnTimer = 0.0f;
		SpawnMonster();
	}
	
	MonsterPoolUpdate();

}

void MonsterManager::Render(HDC hdc)
{
	MonsterPoolRender(hdc);
}

void MonsterManager::MonsterPoolcreate()
{
	monsters.reserve(monsterPoolSize);
	for (int i = 0; i < monsterPoolSize; i++)
	{
		Monster* monster = new Monster(20);
		monster->SetActive(false);
		monsters.push_back(monster);
	}
}

void MonsterManager::MonsterPoolDelete()
{
	for (Monster* monster : monsters)
	{
		delete monster;
	}
}

void MonsterManager::MonsterPoolUpdate()
{
	for (Monster* monster : monsters)
	{
		monster->Update();
	}
}

void MonsterManager::MonsterPoolRender(HDC hdc)
{
	for (Monster* monster : monsters)
	{
		monster->Render(hdc);
	}
}




void MonsterManager::SpawnMonster()
{
	float rendomX = rand() % SCREEN_WIDTH;

	for (Monster* monster : monsters)
	{
		if (!monster->GetActive())
		{
			monster->SetCenter(rendomX, 0);
			monster->SetActive(true);
			
			break;
		}
		
	}
}

