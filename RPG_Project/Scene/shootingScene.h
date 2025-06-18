#pragma once

class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;


private:
	//Player* player;
	//MonsterManager* monsterManager;
};
