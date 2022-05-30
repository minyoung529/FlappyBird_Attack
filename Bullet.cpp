#include "Bullet.h"
#include "console.h"
#include "Core.h"

Bullet::Bullet() : Object({ PLAYER_X + 1, 0 })
{
}

Bullet::Bullet(POSITION position) : Object({position.x + 1, position.y})
{
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
}

void Bullet::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	position.x += 1;

	if (position.x >= MAX_X)
	{
		isDead = true;
	}

	else if (posOnBoard[position.x][position.y] == BLOCK_TYPE::COLUMN)
	{
		isDead = true;
	}
}

void Bullet::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	setcolor(YELLOW, SKYBLUE);

	cout << "¡Ü";
}