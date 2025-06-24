#pragma once

class MonsterManager : public Singleton<MonsterManager>
{

	friend class Singleton;

private:
	int monsterPoolSize = 10;
	float spawnTimer = 0.0f;
	float spawnDelay = 2.0f; // ����: 2�ʸ��� ���� (���� ���� �ӵ��� ���� ����)
	
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

	void SetPlayer(Player* player);


private:
	vector<Monster*> monsters;

};
