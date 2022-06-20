#include "Monster.h"
#include "console.h"
#include "Player.h"
#include "SceneManager.h"
#include "GameScene.h"

Monster::Monster()
{
	player = nullptr;
}

Monster::Monster(POSITION position, Player* player) : Object(position), player(player)
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
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