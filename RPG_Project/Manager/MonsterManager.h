#pragma once

class MonsterManager : public Singleton<MonsterManager>
{

	friend class Singleton;

private:
	int monsterPoolSize = 1;
	float spawnTimer = 0.0f;
	float spawnDelay = 60.0*60.0f; // 예시: 2초마다 생성 (게임 루프 속도에 따라 조절)
	
private:
	MonsterManager();
	~MonsterManager();

public:

	void Update();
	void Render(HDC hdc);
	void MonsterPoolcreate();
	void MonsterPoolDelete();
	void MonsterPoolUpdate();
	void MonsterPoolRender(HDC hdc);
	void SpawnMonster();


private:
	vector<Monster*> monsters;

};
