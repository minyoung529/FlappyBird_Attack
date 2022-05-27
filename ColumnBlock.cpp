#include "ColumnBlock.h"
#include "Core.h"
#include "Player.h"
#include "console.h"

ColumnBlock::ColumnBlock()
	: Object({}, COLUMN)
	, isScorePlus(false)
{
}

ColumnBlock::ColumnBlock(POSITION position)
	: Object(position, COLUMN)
	, isScorePlus(false)
{
}

ColumnBlock::~ColumnBlock()
{
}

void ColumnBlock::Init()
{
}

void ColumnBlock::Update(char posOnBoard)
{
	position.x -= 1;

	if (position.x == -1)
	{
		isDead = true;
	}

	if (position.x < PLAYER_X && !isScorePlus && position.y == 0)
	{
		isScorePlus = true;
		Player::AddScore(1);
	}
}

void ColumnBlock::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	setcolor(GREEN, BLACK);

	cout << "бс";
}