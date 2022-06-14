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
	system("cls");

	if (Player::GetScore() > Player::GetHighScore())
	{
		playsound(WIN);
	}
	else
	{
		playsound(FAIL);
	}
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
	Player::UpdateHighScore();
	_setmode(_fileno(stdout), _O_TEXT);
}

void EndScene::PrintWinText()
{
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
	// 나ㅣㅇ러ㅣ낭러ㅣ낭러 ㅣ나어리넝리마너ㅗ이ㅜ파ㅣㅘ러ㅚ마도ㅜ리 ㅈ다ㅓ
	wcout << L"⣿⣿⣿⣿⣿⣿⣿⠟⠋⠉⠁⠈⠉⠙⠻⢿⡿⠿⠛⠋⠉⠙⠛⢿⣿⣿⣿⣿⣿⣿" << endl;
	wcout << L"⣿⣿⣿⣿⣿⠟⠁⠀⠀⢀⣀⣀⣀⣀⡀⠀⢆⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿  " << endl;
	wcout << L"⣿⣿⣿⣿⠃⠀⠀⠠⠊⠁⠀⠀⠀⠀⠈⠑⠪⡖⠒⠒⠒⠒⠒⠒⠶⠛⠿⣿⣿⣿ " << endl;
	wcout << L"⣿⣿⡿⡇⠀⠀⠀⠀⠀⠀⡠⢔⡢⠍⠉⠉⠩⠭⢑⣤⣔⠲⠤⠭⠭⠤⠴⢊⡻⣿ " << endl;
	wcout << L"⡿⠁⢀⠇⠀⠀⠀⣤⠭⠓⠊⣁⣤⠂⠠⢀⡈⠱⣶⣆⣠⣴⡖⠁⠂⣀⠈⢷⣮⣹ " << endl;
	wcout << L"⠁⠀⠀⠀⠀⠀⠀⠈⠉⢳⣿⣿⣿⡀⠀⠀⢀⣀⣿⡿⢿⣿⣇⣀⣥⣤⠤⢼⣿⣿ " << endl;
	wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡟⠑⠚⢹⡟⠉⣑⠒⢺⡇⡀⠀⡹⠀⠀⣀⣴⣽⣿⣿  " << endl;
	wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⣿⠒⠉⠀⠀⢠⠃⠈⠙⠻⣍⠙⢻⡻⣿⣿⣿  " << endl;
	wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⣀⣘⡄⠀⠀⢸⡇⠀⠀⠀⠘⡇⠀⠀⠀⠘⡄⠀⢱⢸⣿⣿	" << endl;
	wcout << L"⠀⠀⠀⠀⠠⡀⠀⠾⣟⣻⣛⠷⣶⣼⣥⣀⣀⣀⠀⢧⠀⠀⠀⠠⣧⣀⣼⣴⢽⣿  " << endl;
	wcout << L"⠀⠀⠀⠀⠀⠈⠉⠁⠀⠹⡙⠛⠷⣿⣭⣯⣭⣟⣛⣿⣿⣿⣛⣛⣿⣭⣭⣾⣿⣿ " << endl;
	wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡀⠀⠀⣇⠀⠉⠉⠉⡏⠉⠙⠛⠛⡿⣻⣯⣷⣿⣿⣿  " << endl;
	wcout << L"⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢸⠀⠀⠀⡸⠁⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿  " << endl;
	wcout << L"⣿⣿⣿⣿⣶⣶⣦⣤⣤⣤⣷⣤⣄⣈⣆⣤⣤⣧⣶⣷⣿⡻⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
	wcout << L"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⢿⣿⣿⣿⣿⣿⣿" << endl;

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

	if (Player::GetScore() > Player::GetHighScore())
	{
		PrintWinText();
	}
	else
	{
		PrintFailText();
	}

	gotoxy(OFFSET_X + 10, OFFSET_Y + 15);
	cout << "▶ SCORE: " << Player::GetScore();
	gotoxy(OFFSET_X + 10, OFFSET_Y + 17);

	//sfdsdfjsdfusodfna shdfkasfkd
	cout << "▶ HIGH_SCORE: " << Player::GetHighScore();

	gotoxy(OFFSET_X, OFFSET_Y + 23);
	cout << "다시 하려면 SPACE 키를 누르세요..." << endl;
}