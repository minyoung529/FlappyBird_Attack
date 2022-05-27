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
		Player::UpdateHighScore();

		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "|c|o|n|g|r|a|t|u|l|a|t|i|o|n|s|!|" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << endl;

		cout << "축하합니다! 최고기록 갱신!";
	}
	else
	{
		cout << "########    ###    #### ##                   " << endl;
		cout << "##         ## ##    ##  ##                   " << endl;
		cout << "##        ##   ##   ##  ##                   " << endl;
		cout << "######   ##     ##  ##  ##                   " << endl;
		cout << "##       #########  ##  ##                   " << endl;
		cout << "##       ##     ##  ##  ##       ### ### ### " << endl;
		cout << "##       ##     ## #### ######## ### ### ### " << endl;
		cout << endl;

		cout << "다음에는 최고 기록을 갱신해보세요~" << endl;
	}

	cout << endl;
	cout << "SCORE: " << Player::GetScore() << endl;
	cout << "HIGH_SCORE: " << Player::GetHighScore() << endl;

	cout << endl << endl << endl << endl;
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