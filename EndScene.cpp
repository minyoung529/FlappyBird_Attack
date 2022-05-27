#include "EndScene.h"
#include "Core.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "console.h"
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
	cout << "게임 오버~~~~" << endl;
	cout << "다시 하려면 SPACE 키를 누르시오~~" << endl;
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