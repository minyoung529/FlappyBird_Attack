#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetCurrentScene(Scene* scene)
{
	if (curScene)
	{
		curScene->ReleaseScene();
		delete curScene;
	}

	curScene = scene;
	curScene->Init();
}