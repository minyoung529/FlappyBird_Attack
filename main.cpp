#include <Windows.h>
#include "StartScene.h"
#include "SceneManager.h"
#include "Core.h"
#include "console.h"
using namespace std;

int main()
{
	SceneManager* manager = new SceneManager();
	SceneManager::sceneManager = manager;
	Scene* gameScene = new StartScene();

	manager->SetCurrentScene(gameScene);

	cursorview();
	fullscreen();

	while (true)
	{
		manager->Update();

		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8001) != 0)
		{
			system("cls");
			cout << "\n\n\nThanks for Playing!\n\n\n";
			return 0;
		}

		Sleep(manager->GetTimeScale());
	}

	manager->Release();
}