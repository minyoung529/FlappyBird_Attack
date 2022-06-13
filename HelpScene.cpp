#include "HelpScene.h"
#include "StartScene.h"
#include "SceneManager.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>

HelpScene::HelpScene()
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Init()
{
	_setmode(_fileno(stdout), _O_U8TEXT);

	for (int i = 0; i < 6; ++i)
	{
		gotoxy(OFFSET_X + 5, OFFSET_Y + i - 12);
		wcout << title[i];
	}

	_setmode(_fileno(stdout), _O_TEXT);

	int yPos = 0;
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0 && i <= 4) yPos += 5;
		else yPos += 2;

		gotoxy(OFFSET_X - 5, OFFSET_Y + yPos - 5);
		cout << helps[i];
	}

	gotoxy(OFFSET_X - 5, OFFSET_Y + yPos);
	cout << "돌아가려면 H를 누르세요...";
}

void HelpScene::Update()
{
	if ((GetAsyncKeyState('H') & 0x8001) != 0)
	{
		SceneManager::sceneManager->SetCurrentScene(new StartScene());
	}
}

void HelpScene::ReleaseScene()
{
}
