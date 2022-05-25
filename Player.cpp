#include "Player.h"
#include "console.h"
#include "Core.h"

Player::Player()
{
}

Player::Player(POSITION position) : Object(position, PLAYER)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update(char posOnBoard)
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
	{
		position.y -= 2;
	}
	else
	{
		if (position.y >= MAX_Y - 1) return;
		position.y += 1;
	}

	CheckDead(posOnBoard);
}

void Player::CheckDead(char posOnBoard)
{
	if (posOnBoard == FLOOR)
	{

	}
	else if (posOnBoard == COLUMN)
	{

	}
}