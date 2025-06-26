#include "framework.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (pair<string, Scene*> scene : scenes);
	{
		//delete scene.second;
	}
}

void SceneManager::Update()
{
	currentScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	currentScene->Render(hdc);
}

void SceneManager::AddScene(string Key, Scene* scene)
{
	if (scenes.count(Key) > 0)
		return;

	scenes[Key] = scene;
}

void SceneManager::ChageScene(string Key)
{
	if (scenes[Key] == 0)
		return;

	if (currentScene)
	{
		currentScene->End();
	}
	currentScene = scenes[Key];
	currentScene->Start();
}
