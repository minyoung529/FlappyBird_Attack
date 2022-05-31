#include "Item.h"
#include "console.h"

Item::Item() : itemType(ITEM_TYPE::NONE)
{
	position = { };
}

Item::Item(POSITION position) : itemType(ITEM_TYPE::NONE)
{
	this->position = position;
}

Item::Item(POSITION position, ITEM_TYPE itemType) : itemType(itemType)
{
	this->position = position;
}

Item::~Item()
{
}

void Item::Init()
{
}

void Item::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	if (isDead)return;

	if (posOnBoard[position.y][position.x] == BLOCK_TYPE::PLAYER)
	{
		isDead = true;
	}

	position.x -= 1;

	if (position.x == -1)
	{
		isDead = true;
	}
}

void Item::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	setcolor(YELLOW, SKYBLUE);

	switch (itemType)
	{
	case ITEM_TYPE::SLOW:
		cout << "¡å";
		break;

	case ITEM_TYPE::BULLETS:
		cout << "¢À";
		break;

	case ITEM_TYPE::GRAVITY:
		cout << "¡à";
		break;

	case ITEM_TYPE::POWERUP:
		cout << "¢Ý";
		break;
	}
}