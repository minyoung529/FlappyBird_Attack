#include "EndScene.h"
#include "Core.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "console.h"
#include "Player.h"
using namespace std;

EndScene::EndScene()
{
}

EndScene::~EndScene()
{
}

void EndScene::Init()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	system("cls");

	gotoxy(OFFSET_X, OFFSET_Y);

	if (Player::GetScore() > Player::GetHighScore())
	{
		Player::UpdateHighScore();
		// 소리 안 나옴
		PlaySound(MAKEINTRESOURCE(WIN), NULL, SND_RESOURCE | SND_ASYNC);

		for (int i = 0; i < 6; i++)
		{
			gotoxy(OFFSET_X - 45, OFFSET_Y + i);
			wcout << winText[i];
		}

		_setmode(_fileno(stdout), _O_TEXT);
		gotoxy(OFFSET_X, OFFSET_Y + 12);
		cout << "★ 축하합니다! 최고 기록 달성! ★";
	}
	else
	{
		PlaySound(MAKEINTRESOURCE(FAIL), NULL, SND_RESOURCE | SND_ASYNC);

		for (int i = 0; i < 10; i++)
		{
			gotoxy(OFFSET_X, OFFSET_Y + i);
			wcout << failText[i];
		}

		_setmode(_fileno(stdout), _O_TEXT);
		gotoxy(OFFSET_X, OFFSET_Y + 12);
		cout << "▶ 최고 기록 달성 실패! 노력하세요~ ◀";
	}


	gotoxy(OFFSET_X + 10, OFFSET_Y + 15);
	cout << "▶ SCORE: " << Player::GetScore();
	gotoxy(OFFSET_X + 10, OFFSET_Y + 17);
	cout << "▶ HIGH_SCORE: " << Player::GetHighScore();

	gotoxy(OFFSET_X, OFFSET_Y + 25);
	cout << "다시 하려면 SPACE 키를 누르세요..." << endl;
}

void EndScene::Update()
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
	{
		system("cls");
		SceneManager::sceneManager->SetCurrentScene(new GameScene());
	}
}

void EndScene::ReleaseScene()
{
}