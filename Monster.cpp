#include "Monster.h"
#include "console.h"

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
}

void Monster::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
}

void Monster::Render(int offsetX, int offsetY)
{
	setcolor(RED, SKYBLUE);
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	cout << "бубу";

	gotoxy(position.x * 2 + offsetX, position.y + offsetY + 1);
	setcolor(RED, YELLOW);
	cout << "бсбс";

	setcolor(WHITE, BLACK);
}