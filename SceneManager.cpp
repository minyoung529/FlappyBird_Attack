#include "SceneManager.h"
#include "console.h"

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
	setcolor(WHITE, BLACK);
	system("cls");

	if (curScene)
	{
		curScene->ReleaseScene();
		delete curScene;
		curScene = nullptr;
	}

	curScene = scene;

	if (curScene)
		curScene->Init();
}