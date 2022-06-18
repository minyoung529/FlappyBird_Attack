#include "GameScene.h"
#include "Player.h"
#include "console.h"
#include "Item.h"
#include "Monster.h"
#include "Background.h"

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
				map[y][x] = BLOCK_TYPE::FLOOR;
				continue;
			}

			map[y][x] = BLOCK_TYPE::EMPTY;
		}
	}

	POSITION pos = { MAX_X - 2, MAX_Y / 2 - 1 };
	player = new Player({ PLAYER_X, MAX_Y / 2 - 3 });
	player->Init();
	currentObjects.push_back(player);

	monster = new Monster(pos);
	monster->Init();
	currentObjects.push_back(monster);


	setcolor(WHITE, BLACK);

	DrawFrame();
	DrawSticksAndButtons();
}

void GameScene::Update()
{
	if (isRelease) return;

	if (updateTime % 15 == 0)
	{
		Item* item = new Item({ MAX_X - 1, rand() % (MAX_Y - 2) },
			(ITEM_TYPE)(rand() % (int)ITEM_TYPE::COUNT));
		item->Init();
		currentObjects.push_back(item);
	}

	if (updateTime % 7 == 0)
	{
		GenerateColumn(currentObjects);
	}

	POSITION pos = { MAX_X - 2, MAX_Y / 2 - 1 };

	map[pos.y + 1][pos.x] = BLOCK_TYPE::MONSTER;

	for (int i = 0; i < currentObjects.size(); i++)
	{
		if (!currentObjects[i])continue;
		if (currentObjects.empty() || i >= currentObjects.size())continue;

		POSITION pos = currentObjects[i]->GetPosition();
		currentObjects[i]->Update(map);

		if (isRelease)
		{
			return;
		}

		if (IN_SCREEN(pos.x, pos.y))
			map[pos.y][pos.x] = BLOCK_TYPE::EMPTY;

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
		currentObjects[0] = nullptr;
		currentObjects.erase(currentObjects.begin());
	}
}

Object* GameScene::FindObjectOfType(BLOCK_TYPE type)
{
	for (Object* obj : currentObjects)
	{
		if (obj->GetObjectType() == type)
			return obj;
	}
}

vector<Object*> GameScene::FindObjectsOfType(BLOCK_TYPE type)
{
	vector<Object*> objs;
	for (Object* obj : currentObjects)
	{
		if (obj->GetObjectType() == type)
		{
			objs.push_back(obj);
		}
	}

	return objs;
}

void GameScene::Draw()
{
	if (isRelease) return;

	setcolor(BLACK, RED);
	gotoxy(OFFSET_X, OFFSET_Y - 3);
	cout << "¢º HIGHSCORE: " << Player::GetHighScore() << endl;

	setcolor(BLACK, GREEN);
	gotoxy(OFFSET_X, OFFSET_Y - 2);
	cout << "¢º SCORE: " << Player::GetScore() << endl;


	int bgColor = (player->GetIsReverseGravity()) ? BLACK : SKYBLUE;

	gotoxy(OFFSET_X, OFFSET_Y);

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			switch (map[y][x])
			{
			case BLOCK_TYPE::EMPTY:

				setcolor(WHITE, bgColor);
				if (x % 2 == 0)
				{
					if (y % 2 == 0)
						cout << "* ";
					else
						cout << " *";
				}
				else
					cout << "  ";
				break;

			case BLOCK_TYPE::FLOOR:
				setcolor(BLACK, bgColor);
				cout << "¡ã";
				break;

			default:
				(WHITE, bgColor);
				cout << "  ";
			}
		}
		cout << endl;
		gotoxy(OFFSET_X, OFFSET_Y + y);
	}

	for (int i = 0; i < currentObjects.size(); i++)
	{
		currentObjects[i]->Render(OFFSET_X, OFFSET_Y);
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