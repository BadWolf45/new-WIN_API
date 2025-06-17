#pragma once

class MonsterManager
{
private:
	int monsterPoolSize = 4;
	
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
