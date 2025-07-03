#include "framework.h"
#include "MonsterManager.h"


MonsterManager* Singleton<MonsterManager>::instance = nullptr;
MonsterManager::MonsterManager()
{

	MonsterPoolcreate();
	spawnPoints.push_back(new SpawnPoint(Vector2(100.0f, 100.0f), 1.0f));
	spawnPoints.push_back(new SpawnPoint(Vector2(200.0f, 100.0f), 1.0f));

	for (int i = 0; i < spawnPoints.size(); ++i)
	{
		SpawnMonsterAtPoint(i);
	}
}


MonsterManager::~MonsterManager()
{
	MonsterPoolDelete();
}

void MonsterManager::Update()
{
	for (int i = 0; i < spawnPoints.size(); ++i)
	{
		SpawnPoint* sp = spawnPoints[i]; 

		if (!sp->SpawnActive) 
		{
			sp->RespawnCurrentTime += DELTA; 

			if (sp->RespawnCurrentTime >= sp->RespawnTime) 
			{
				SpawnMonsterAtPoint(i);
			}
		}
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

void MonsterManager::NotifyMonsterDeath(Monster* deadMonster) 
{
	
	int spIndex = deadMonster->GetSpawnPointIndex();

	if (spIndex != -1 && spIndex < spawnPoints.size())
	{
		SpawnPoint* sp = spawnPoints[spIndex]; 

		sp->SpawnActive = false; 
		sp->RespawnCurrentTime = 0.0f;
		sp->monsterIndexPool = -1;
	}
	
}

void MonsterManager::SpawnMonsterAtPoint(int spawnPointIndex)
{
	if (spawnPointIndex < 0 || spawnPointIndex >= spawnPoints.size()) return; 

	SpawnPoint* sp = spawnPoints[spawnPointIndex]; 

	
	for (int i = 0; i < monsters.size(); ++i)
	{
		Monster* monster = monsters[i];
		if (!monster->GetActive()) 
		{
			monster->SetCenter(sp->center.x, sp->center.y);
			monster->SetActive(true); 
			monster->SetSpawnPointIndex(spawnPointIndex); 
			monster->ResetHealth(); 

			sp->SpawnActive = true;
			sp->RespawnCurrentTime = 0.0f;
			sp->monsterIndexPool = i;

			
			if (player)
			{
				monster->SetPlayer(player);
			}
			return; 
		}
	}
}


void MonsterManager::SetPlayer(Player* player)
{
	this->player = player;
	for (Monster* monster : monsters)
	{
		monster->SetPlayer(player);

	}
}


