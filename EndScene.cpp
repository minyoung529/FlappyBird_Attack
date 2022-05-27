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
	cout << "���� ����~~~~" << endl;
	cout << "�ٽ� �Ϸ��� SPACE Ű�� �����ÿ�~~" << endl;
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