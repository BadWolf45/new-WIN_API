#pragma once
#include "framework.h"

class MonsterManager : public Singleton<MonsterManager>
{

	friend class Singleton;

private:
	int monsterPoolSize = 10;
	//float spawnTimer = 0.0f;
	//float spawnDelay = 2.0f; // 예시: 2초마다 생성 (게임 루프 속도에 따라 조절)
	
protected:
	MonsterManager();
	~MonsterManager();

public:

	void Update();
	void Render(HDC hdc);
	void MonsterPoolcreate();
	void MonsterPoolDelete();
	void MonsterPoolUpdate();
	void MonsterPoolRender(HDC hdc);
	void NotifyMonsterDeath(Monster* deadMonster);
	void SpawnMonsterAtPoint(int spawnPointIndex);
	//void SpawnMonster();
	void SetPlayer(Player* player);

	
private:
	vector<Monster*> monsters;
	vector<SpawnPoint*> spawnPoints;
	Player* player = nullptr;
	

};
