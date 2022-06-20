#include "EndScene.h"
#include "Core.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "console.h"
#include "Player.h"
using namespace std;

EndScene::EndScene() : score(0), highScore(0)
{
}

EndScene::~EndScene()
{
}

void EndScene::Init()
{
	score = Player::GetScore();
	highScore = Player::GetHighScore();
	system("cls");

	if (score > highScore)
	{
		playsound(L"Data/WinSound.wav");
		Player::UpdateHighScore();
	}
	else
		playsound(L"Data/Fail.wav");
}

void EndScene::Update()
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
	{
		SceneManager::sceneManager->SetCurrentScene(new GameScene());
		return;
	}

	setcolor(updateTime % 15 + 1, BLACK);

	PrintAllText();
	updateTime++;
}

void EndScene::ReleaseScene()
{
	_setmode(_fileno(stdout), _O_TEXT);
}

void EndScene::PrintWinText()
{
	for (int i = 0; i < 20; i++)
	{
		gotoxy(OFFSET_X - 50, OFFSET_Y + i - 20);
		wcout << winImage[i];
	}

	for (int i = 0; i < 21; i++)
	{
		gotoxy(OFFSET_X + 40, OFFSET_Y + i - 20);
		wcout << winImage2[i];
	}

	for (int i = 0; i < 6; i++)
	{
		gotoxy(OFFSET_X - 45, OFFSET_Y + i);
		wcout << winText[i];
	}

	_setmode(_fileno(stdout), _O_TEXT);
	gotoxy(OFFSET_X, OFFSET_Y + 12);
	cout << "★ 축하합니다! 최고 기록 달성! ★";
}

void EndScene::PrintFailText()
{
	for (int i = 0; i < 15; i++)
	{
		gotoxy(OFFSET_X - 50, OFFSET_Y + i - 5);
		wcout << failImage[i];
	}

	for (int i = 0; i < 14; i++)
	{
		gotoxy(OFFSET_X + 60, OFFSET_Y + i - 5);
		wcout << failImage2[i];
	}

	for (int i = 0; i < 10; i++)
	{
		gotoxy(OFFSET_X, OFFSET_Y + i);
		wcout << failText[i];
	}

	_setmode(_fileno(stdout), _O_TEXT);

	gotoxy(OFFSET_X, OFFSET_Y + 12);
	cout << "▶ 최고 기록 달성 실패! 노력하세요~ ◀";
}

void EndScene::PrintAllText()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	gotoxy(OFFSET_X, OFFSET_Y);

	if (score > highScore)
	{
		PrintWinText();
	}
	else
	{
		PrintFailText();
	}

	gotoxy(OFFSET_X + 10, OFFSET_Y + 15);
	cout << "▶ SCORE: " << score          ;
	gotoxy(OFFSET_X + 10, OFFSET_Y + 17);

	if (score > highScore)
		cout << "▶ HIGH_SCORE: " << score;
	else
		cout << "▶ HIGH_SCORE: " << highScore;

	gotoxy(OFFSET_X, OFFSET_Y + 23);
	cout << "다시 하려면 SPACE 키를 누르세요..." << endl;
}