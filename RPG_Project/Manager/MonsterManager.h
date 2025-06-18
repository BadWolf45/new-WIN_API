#pragma once

class MonsterManager
{
private:
	int monsterPoolSize = 1;
	float spawnTimer = 0.0f;
	float spawnDelay = 120.0f; // 예시: 2초마다 생성 (게임 루프 속도에 따라 조절)
	
private:
	MonsterManager();
	~MonsterManager();

public:

	static MonsterManager* GET()
	{

		if (instance == nullptr)
		{
			instance = new MonsterManager();
		}
		return instance;
	}
	static void Delete()
	{
		delete instance;
	}

	void Update();
	void Render(HDC hdc);

	


private:
	static MonsterManager* instance;
	vector<Monster*> monsters;
};
