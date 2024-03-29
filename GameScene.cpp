#include "GameScene.h"
#include "Player.h"
#include "console.h"
#include "Item.h"
#include "Monster.h"
#include "Background.h"
#include "SceneManager.h"
#include "EndScene.h"

#include <string>

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

	monster = new Monster(pos, player);
	monster->Init();
	currentObjects.push_back(monster);


	setcolor(WHITE, BLACK);

	DrawFrame();
	DrawSticksAndButtons();
	playbgm();
}

void GameScene::Update()
{
	if (player->GetIsDead())
	{
		isRelease = true;
		SceneManager::sceneManager->SetCurrentScene(new EndScene());
		return;
	}
	if (isRelease) return;

	if (updateTime % 15 == 0)
	{
		Item* item = new Item({ MAX_X - 1, rand() % (MAX_Y - 2) },
			(ITEM_TYPE)(rand() % (int)ITEM_TYPE::COUNT), player);
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
		if (currentObjects.empty() || i >= currentObjects.size())break;
		if (isRelease)return;

		POSITION pos = currentObjects[i]->GetPosition();
		currentObjects[i]->Update(map);

		if (IN_SCREEN(pos.x, pos.y))
		{
			map[pos.y][pos.x] = BLOCK_TYPE::EMPTY;
		}

		pos = currentObjects[i]->GetPosition();

		if (IN_SCREEN(pos.x, pos.y))
		{
			map[pos.y][pos.x] = currentObjects[i]->GetObjectType();
		}
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

void GameScene::Draw()
{
	if (isRelease) return;

	gotoxy(3, 3);
	setcolor(BLACK, WHITE);
	cout << " 종료하려면 esc를 누르시오... ";

	setcolor(BLACK, RED);
	gotoxy(OFFSET_X, OFFSET_Y - 2);

	if (Player::GetScore() > Player::GetHighScore())
		cout << " ▶ HIGHSCORE: " << Player::GetScore() << " " << endl;
	else
		cout << " ▶ HIGHSCORE: " << Player::GetHighScore() << " " << endl;

	DrawNumber();

	int bgColor;

	if (player)
		bgColor = (player->GetIsReverseGravity()) ? BLACK : SKYBLUE;
	if (currentObjects.size() == 0)return;

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
				cout << "▲";
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

void GameScene::DrawNumber()
{
	setcolor(WHITE, BLACK);
	string score = to_string(Player::GetScore());
	int xOffset = 16 + score.size() * -3;

	for (int k = 0; k < score.size(); k++)
	{
		for (int i = 0; i < 7; i++)
		{
			int start = (score[k] - '0') * 9;
			for (int j = start, count = 0; j < start + 9; j++, count++)
			{
				gotoxy(OFFSET_X + xOffset + count + k * 9, OFFSET_Y - 10 + i);

				if (j >= 0 && j < 91)
					cout << numbers[i][j];
			}

			cout << endl;
		}
	}
}