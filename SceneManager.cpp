#include "SceneManager.h"

SceneManager* SceneManager::sceneManager = nullptr;

SceneManager::SceneManager() : curScene(nullptr)
{
	if (!sceneManager)
	{
		sceneManager = this;
	}
}

SceneManager::~SceneManager()
{
	delete curScene;
	delete sceneManager;
}

void SceneManager::SetCurrentScene(Scene* scene)
{
	if (curScene)
	{
		curScene->ReleaseScene();
		delete curScene;
		curScene = nullptr;
	}

	curScene = scene;
	curScene->Init();
}