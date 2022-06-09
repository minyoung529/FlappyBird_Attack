#include "Bullet.h"
#include "Player.h"
#include "console.h"
#include "Core.h"

Bullet::Bullet() : Object({ PLAYER_X + 1, 0 })
{
}

Bullet::Bullet(POSITION position, int damage) : Object({ position.x + 1, position.y }), damage(damage)
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
	if (isDead)return;

	if (posOnBoard[position.y][position.x] == BLOCK_TYPE::MONSTER)
	{
		Player::AddScore(damage);
		isDead = true;
	}

	position.x += 1;

	if (position.x >= MAX_X - 1)
	{
		isDead = true;
	}
}

void Bullet::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);

	if (damage > 3)
	{
		setcolor(RED, SKYBLUE);
	}
	else
	{
		setcolor(YELLOW, SKYBLUE);
	}

	cout << "��";
}