#include "console.h"

#include "SceneManager.h"
#include "StartScene.h"
#include "HelpScene.h"
#include "Background.h"
#include "GameScene.h"
#include "resource.h"
#include <mmsystem.h>

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{
	setcolor(YELLOW, SKYBLUE);
	playsound(BGM);

	system("cls");
}

void StartScene::Update()
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
	{
		SceneManager::sceneManager->SetCurrentScene(new GameScene());
		return;
	}

	else if ((GetAsyncKeyState('H') & 0x8001) != 0)
	{
		SceneManager::sceneManager->SetCurrentScene(new HelpScene());
		return;
	}

	_setmode(_fileno(stdout), _O_TEXT);

	RenderBirds();
	RenderTitle();
	RenderButton();

	++updateTime;
}

void StartScene::ReleaseScene()
{
	_setmode(_fileno(stdout), _O_TEXT);
}

void StartScene::RenderTitle()
{
	setcolor(YELLOW, SKYBLUE);

	for (int i = 0; i < 6; i++)
	{
		if (updateTime % 2 == 0)
			gotoxy(OFFSET_X - 20, OFFSET_Y + i - 9);
		else
			gotoxy(OFFSET_X - 20, OFFSET_Y + i - 8);

		cout << "                                                                                ";
	}

	_setmode(_fileno(stdout), _O_U8TEXT);
	for (int i = 0; i < 6; i++)
	{
		if (updateTime % 2 == 0)
			gotoxy(OFFSET_X - 20, OFFSET_Y + i - 8);
		else
			gotoxy(OFFSET_X - 20, OFFSET_Y + i - 9);

		wcout << title[i];
	}
}

void StartScene::RenderButton()
{
	_setmode(_fileno(stdout), _O_TEXT);

	setcolor(BLACK, GREEN);
	GetButton("Play", "Space", OFFSET_Y + 7);

	setcolor(WHITE, RED);
	GetButton("Help", "H", OFFSET_Y + 12);

	setcolor(WHITE, BLACK);
	GetButton("Quit", "Esc", OFFSET_Y + 17);

	setcolor(YELLOW, SKYBLUE);
}

void StartScene::GetButton(const char* name, const char* key, int y)
{
	string str[3] = { "", };

	for (int i = 0; i < 20; i++)
	{
		str[0] += " ";
		str[2] += " ";
	}

	int space = 20 - ((string)name).size() - ((string)key).size() - 3;

	for (int i = 0; i < space / 2; i++) str[1] += " ";

	str[1] += name;
	str[1] += " (";
	str[1] += key;
	str[1] += ")";

	for (int i = 0; i < space / 2; i++) str[1] += " ";

	for (int i = 0; i < 3; i++)
	{
		gotoxy(OFFSET_X + FRAME_SIZE_X / 2 - 13, y + i);
		cout << str[i] << endl << endl;
	}
}

void StartScene::RenderBirds()
{
	for (int x = 10; x < 190; x += 20)
	{
		for (int y = 5; y <= 50; y += 20)
		{
			if (x > OFFSET_X - MAX_X && x < OFFSET_X + MAX_X + FRAME_SIZE_X)continue;

			gotoxy(x, y + 2);
			cout << "           ";
			gotoxy(x, y - 1);
			cout << "           ";
			gotoxy(x, y);
			cout << "           ";

			for (int i = 0; i < 3; i++)
			{
				if (updateTime % 2 == 1)
					gotoxy(x, y + i);

				else
					gotoxy(x, y + i - 1);

				cout << bird[i];
			}
		}
	}
}