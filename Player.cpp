#include "Player.h"
#include "console.h"
#include "Core.h"
#include "EndScene.h"
#include "SceneManager.h"
#include "Bullet.h"

int Player::score = 0;
int Player::highScore = 0;

Player::Player() : Object({}, BLOCK_TYPE::PLAYER)
{
	score = 0;
}

Player::Player(POSITION position) : Object(position, BLOCK_TYPE::PLAYER)
{
	score = 0;
}

Player::~Player()
{
	while (!bullets.empty())
	{
		delete bullets[0];
		bullets[0] = nullptr;
		bullets.erase(bullets.begin());
	}
}

void Player::Init()
{
}

void Player::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	CheckDead(posOnBoard);

	if ((GetAsyncKeyState(VK_SPACE) & 0x8001) != 0)
	{
		if (!isReverseGravity)
		{
			position.y -= 2;
		}

		if (isReverseGravity)
		{
			position.y += 2;
		}

		playsound(JUMP);
	}
	else
	{
		if (!isReverseGravity)
			position.y += 1;
		else
			position.y -= 1;
	}

	if ((GetAsyncKeyState(VK_LSHIFT) & 0x8001) != 0)
	{
		int damage = (isStrong) ? 5 : 3;
		Bullet* newBullet = new Bullet(position, damage);
		newBullet->Init();
		bullets.push_back(newBullet);

		playsound(SHOOT);
	}

	CheckDead(posOnBoard);

	for (int i = 0; i < bullets.size(); i++)
	{
		if (isDead) return;

		if (bullets[i])
		{
			bullets[i]->Update(posOnBoard);
		}
	}

	DeleteObject();
}

void Player::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);

	int bgColor = (isReverseGravity) ? BLACK : SKYBLUE;
	setcolor(YELLOW, bgColor);

	cout << "¡Ú";

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->GetIsDead())continue;
		bullets[i]->Render(offsetX, offsetY);
	}

	setcolor(WHITE, BLACK);
}

void Player::CheckDead(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
	if (isDead) return;

	if (position.y >= MAX_Y - 2 || posOnBoard[position.y][position.x] == BLOCK_TYPE::COLUMN ||
		position.y < 0)
	{
		isDead = true;
		Render(OFFSET_X, OFFSET_Y);
		SceneManager::sceneManager->SetCurrentScene(new EndScene());
	}
}

void Player::DeleteObject()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		Bullet* obj = bullets[i];

		if (obj)
		{
			if (!obj->GetIsDead()) continue;

			bullets.erase(bullets.begin() + i);
			delete obj;
			obj = nullptr;
			i--;
		}
	}
}