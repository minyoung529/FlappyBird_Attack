#include "Item.h"
#include "console.h"
#include "Player.h"

#include "Slow.h"
#include "Gravity.h"
#include "PowerUp.h"

#include "GameScene.h"
#include "SceneManager.h"

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

Item::Item(POSITION position, ITEM_TYPE itemType, Player* player) : itemType(itemType), player(player)
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

	position.x -= 1;

	if (position.x == -1)
	{
		isDead = true;
		return;
	}

	if (posOnBoard[position.y][position.x] == BLOCK_TYPE::PLAYER)
	{
		isStart = true;

		switch (itemType)
		{
		case ITEM_TYPE::SLOW:
			item = new Slow();
			playsound(/*L"Data/Slow.wav"*/SLOW_ITEM);
			break;

		case ITEM_TYPE::GRAVITY:
			playsound(/*L"Data/Gravity.wav"*/GRAVITY_ITEM);
			item = new Gravity();
			break;

		case ITEM_TYPE::POWERUP:
			item = new PowerUp();
			playsound(/*L"Data/Power.wav"*/POWER);
			break;
		}

		if (item)
			item->Init();
	}
}

void Item::Render(int offsetX, int offsetY)
{
	if (isStart || isDead) return;

	gotoxy(position.x * 2 + offsetX, position.y + offsetY);

	int bgColor = (player->GetIsReverseGravity()) ? BLACK : SKYBLUE;

	switch (itemType)
	{
	case ITEM_TYPE::SLOW:
	case ITEM_TYPE::POWERUP:
		setcolor(YELLOW, bgColor);
		break;

	case ITEM_TYPE::GRAVITY:
		setcolor(RED, bgColor);
		break;
	}

	switch (itemType)
	{
	case ITEM_TYPE::SLOW:
		cout << "¡å";
		break;

	case ITEM_TYPE::GRAVITY:
		cout << "¢Õ";
		break;

	case ITEM_TYPE::POWERUP:
		cout << "¢Ý";
		break;
	}
}