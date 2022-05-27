#include "Player.h"
#include "console.h"
#include "Core.h"
#include "EndScene.h"
#include "SceneManager.h"

int Player::score = 0;
int Player::highScore = 0;

Player::Player() : Object({}, PLAYER)
{
	score = 0;
}

Player::Player(POSITION position) : Object(position, PLAYER)
{
	score = 0;
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

void Player::Render(int offsetX, int offsetY)
{
	gotoxy(position.x * 2 + offsetX, position.y + offsetY);
	setcolor(YELLOW, SKYBLUE);

	cout << "¡Ú";
}

void Player::CheckDead(char posOnBoard)
{
	if (isDead) return;

	if (position.y == MAX_Y - 1 || posOnBoard == COLUMN)
	{
		isDead = true;
		SceneManager::sceneManager->SetCurrentScene(new EndScene());
	}
}