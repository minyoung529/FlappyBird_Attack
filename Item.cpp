#include "Item.h"
#include "console.h"
#include "Player.h"

#include "Slow.h"
#include "Gravity.h"
#include "PowerUp.h"

#include <mmsystem.h>

Item::Item() : itemType(ITEM_TYPE::NONE)
{
	position = { };
	item = nullptr;
}

Item::Item(POSITION position) : itemType(ITEM_TYPE::NONE)
{
	this->position = position;
	item = nullptr;
}

Item::Item(POSITION position, ITEM_TYPE itemType) : itemType(itemType)
{
	this->position = position;
	item = nullptr;
}

Item::~Item()
{
	if (item) delete item;
	item = nullptr;
}

void Item::Init()
{
}

void Item::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	if (timer > 10) isDead = true;
	if (isDead)return;
	if (isStart)
	{
		timer++;
		if (item)
		{
			item->Update({});
		}
		return;
	}

	if (posOnBoard[position.y][position.x] == BLOCK_TYPE::PLAYER)
	{
		isStart = true;

		switch (itemType)
		{
		case ITEM_TYPE::SLOW:
			item = new Slow();
			PlaySound(MAKEINTRESOURCE(SLOW_ITEM), NULL, SND_RESOURCE | SND_ASYNC);
			break;

		case ITEM_TYPE::BULLETS:
			break;

		case ITEM_TYPE::GRAVITY:
			PlaySound(MAKEINTRESOURCE(GRAVITY_ITEM), NULL, SND_RESOURCE | SND_ASYNC);
			item = new Gravity();
			break;

		case ITEM_TYPE::POWERUP:
			item = new PowerUp();
			PlaySound(MAKEINTRESOURCE(POWER), NULL, SND_RESOURCE | SND_ASYNC);
			break;
		}

		if (item)
			item->Init();
	}

	position.x -= 1;

	if (position.x == -1)
	{
		isDead = true;
	}
}

void Item::Render(int offsetX, int offsetY)
{
	if (isStart || isDead) return;

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