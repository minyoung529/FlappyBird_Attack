#include "GameScene.h"
#include "Player.h"
#include "console.h"

GameScene::GameScene()
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

	player = new Player({ 2, MAX_Y / 2 });
	curSceneObjects.push_back(player);
}

void GameScene::Update()
{
	if (updateTime % 10 == 0)
	{
		GenerateColumn(curSceneObjects);
	}

	for (int i = 0; i < curSceneObjects.size(); i++)
	{
		POSITION pos = curSceneObjects[i]->GetPosition();

		curSceneObjects[i]->Update(map[pos.y][pos.x]);

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = EMPTY;

		pos = curSceneObjects[i]->GetPosition();

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = curSceneObjects[i]->GetObjectType();
	}

	DeleteObject();
	Draw();

	updateTime++;
}

void GameScene::ReleaseScene()
{
	int size = curSceneObjects.size();
	int offset = 0;

	for (int i = 0; i < size; i++)
	{
		curSceneObjects.erase(curSceneObjects.begin() + i);
		delete curSceneObjects[i];
	}
}

void GameScene::Draw()
{
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

			case PLAYER:
				setcolor(YELLOW, SKYBLUE);
				cout << "б▄";
				break;

			case COLUMN:
				setcolor(GREEN, SKYBLUE);
				cout << "бс";
				break;

			case FLOOR:
				setcolor(BLACK, SKYBLUE);
				cout << "бу";
				break;
			}
		}

		setcolor(WHITE, BLACK);
		cout << endl;
	}
}

void GameScene::DeleteObject()
{
	for (int i = 0; i < curSceneObjects.size(); i++)
	{
		Object* obj = curSceneObjects[i];

		if (obj->GetIsDead())
		{
			curSceneObjects.erase(curSceneObjects.begin() + i);

			POSITION pos = obj->GetPosition();

			delete obj;

			i--;
		}
	}
}