#include "Monster.h"
#include "console.h"
#include "Player.h"
#include "SceneManager.h"
#include "GameScene.h"

Monster::Monster()
{
}

Monster::Monster(POSITION position) : Object(position)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
	Object* obj = dynamic_cast<GameScene*>(SceneManager::sceneManager->GetCurrentScene())->
			FindObjectOfType(BLOCK_TYPE::PLAYER);

	player = dynamic_cast<Player*>(obj);
}

void Monster::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
}

void Monster::Render(int offsetX, int offsetY)
{
	if (!player) return;

	int bgColor = (player->GetIsReverseGravity()) ? BLACK : SKYBLUE;

	setcolor(RED, bgColor);
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	cout << "бубу";

	gotoxy(position.x * 2 + offsetX, position.y + offsetY + 1);
	setcolor(BLACK, WHITE);
	cout << "бсбс";

	setcolor(WHITE, BLACK);
}