#include <Windows.h>
#include "StartScene.h"
#include "SceneManager.h"
#include "Core.h"
#include "Background.h"
#include "console.h"
using namespace std;

int main()
{
	cursorview();
	fullscreen();
	changefont();

	SceneManager* manager = new SceneManager();
	SceneManager::sceneManager = manager;
	Scene* gameScene = new StartScene();

	manager->SetCurrentScene(gameScene);


	while (true)
	{
		manager->Update();

		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8001) != 0)
		{
			setcolor(SKYBLUE, WHITE);
			system("cls");
			DrawCharacter();
			gotoxy(86, 17);
			cout << "Thanks for Playing!\n\n\n\n\n";
			manager->Release();

			setcolor(WHITE, WHITE);
			return 0;
		}

		Sleep(manager->GetTimeScale());
	}

	return 0;
}