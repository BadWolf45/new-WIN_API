#pragma once

class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;
	
	void MainMenu();
	void Shop();



	void Start();
	void End();
private:
	Player* player;
	//MonsterManager* monsterManager;
	Button* mainButton;
	

};
