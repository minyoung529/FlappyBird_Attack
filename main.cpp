#include <Windows.h>
#include "StartScene.h"
#include "SceneManager.h"
#include "Core.h"
#include "Background.h"
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

	CONSOLE_FONT_INFOEX cfi = {};
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"NSimSun");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


	while (true)
	{
		manager->Update();

		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8001) != 0)
		{
			system("cls");
			DrawCharacter();
			cout << "\n\n\nThanks for Playing!\n\n\n";
			return 0;
		}

		Sleep(manager->GetTimeScale());
	}

	manager->Release();

	DrawCharacter();
}