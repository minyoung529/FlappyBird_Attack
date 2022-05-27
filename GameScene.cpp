#include "GameScene.h"
#include "Player.h"
#include "console.h"

GameScene::GameScene()
	: player(nullptr)
	, currentObjects{}
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (y == MAX_Y - 1)
			{
				map[y][x] = FLOOR;
				continue;
			}

			map[y][x] = EMPTY;
		}
	}

	player = new Player({ PLAYER_X, MAX_Y / 2 });
	currentObjects.push_back(player);
}


void GameScene::Update()
{
	if (isRelease) return;

	if (updateTime % 10 == 0)
	{
		GenerateColumn(currentObjects);
	}

	for (int i = 0; i < currentObjects.size(); i++)
	{
		if (!currentObjects[i])continue;
		if (currentObjects.empty() || i >= currentObjects.size())continue;

		POSITION pos = currentObjects[i]->GetPosition();
		currentObjects[i]->Update(map[pos.y][pos.x]);

		if (isRelease || currentObjects.empty() || i >= currentObjects.size())
		{
			return;
		}

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = EMPTY;

		pos = currentObjects[i]->GetPosition();

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = currentObjects[i]->GetObjectType();
	}

	DeleteObject();
	Draw();

	updateTime++;
}

void GameScene::ReleaseScene()
{
	isRelease = true;
	int index = 0;

	while (!currentObjects.empty())
	{
		delete currentObjects[0];
		currentObjects.erase(currentObjects.begin());
	}
}

void GameScene::Draw()
{
	if (isRelease) return;

	gotoxy(0, 0);
	cout << "SCORE: " << Player::GetScore() << endl;
	gotoxy(0, 10);

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			switch (map[y][x])
			{
			case EMPTY:
				setcolor(WHITE, SKYBLUE);
				cout << "  ";
				break;

			case FLOOR:
				setcolor(BLACK, SKYBLUE);
				cout << "бу";
				break;

			default:
				(WHITE, SKYBLUE);
				cout << "  ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < currentObjects.size(); i++)
	{
		currentObjects[i]->Render(0, 10);
	}
}

void GameScene::DeleteObject()
{
	if (isRelease)return;

	for (int i = 0; i < currentObjects.size(); i++)
	{
		if (isRelease || i < 0)return;

		Object* obj = currentObjects[i];

		if (obj)
		{
			if (!obj->GetIsDead()) continue;

			currentObjects.erase(currentObjects.begin() + i);
			delete obj;
			obj = nullptr;
			i--;
		}
	}
}