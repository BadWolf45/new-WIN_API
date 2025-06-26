#pragma once
#include "framework.h"

class SceneManager : public Singleton <SceneManager>
{
public:
	SceneManager();
	~SceneManager();


	void Update();
	void Render(HDC hdc);

	void AddScene(string Key, Scene* scene);
	void ChageScene(string Key);

	

private:
	Scene* currentScene;
	
	unordered_map<string, Scene*> scenes;
};
