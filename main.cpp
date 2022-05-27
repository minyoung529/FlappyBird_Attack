#include <Windows.h>
#include "GameScene.h"
#include "SceneManager.h"
#include "Core.h"
using namespace std;

int main()
{
	SceneManager::sceneManager = new SceneManager();
	Scene* gameScene = new GameScene();

	SceneManager::sceneManager->SetCurrentScene(gameScene);

	while (true)
	{
		SceneManager::sceneManager->Update();
		Sleep(250);
	}

	SceneManager::sceneManager->Release();
}