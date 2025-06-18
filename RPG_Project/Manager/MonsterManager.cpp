#include "framework.h"
#include "MonsterManager.h"

MonsterManager* MonsterManager::instance = nullptr;

MonsterManager::MonsterManager()
{
	monsters.reserve(monsterPoolSize);
	for (int i = 0; i < monsterPoolSize; i++)
	{
		Monster* monster = new Monster(20);
		//monster->SetActive(false);
		monsters.push_back(monster);
	}
}

MonsterManager::~MonsterManager()
{
	for (Monster* monster : monsters)
	{
		delete monster;
	}
}

void MonsterManager::Update()
{
	for (Monster* monster : monsters)
	{
		monster->Update();
	}
}

void MonsterManager::Render(HDC hdc)
{
	for (Monster* monster : monsters)
	{
			monster->Render(hdc);
	}
}

