#include <Windows.h>
#include "Scene.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "Core.h"
using namespace std;

int main()
{
	sceneManager = new SceneManager();
	Scene* gameScene = new GameScene();

	sceneManager->SetCurrentScene(gameScene);

	while (true)
	{
		sceneManager->Update();
		Sleep(250);
	}

	sceneManager->Release();
}