#include "Bullet.h"
#include "Player.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "console.h"
#include "Core.h"
#include "Player.h"

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
	Object* obj = dynamic_cast<GameScene*>(SceneManager::sceneManager->GetCurrentScene())->
		FindObjectOfType(BLOCK_TYPE::PLAYER);

	player = dynamic_cast<Player*>(obj);
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

	int bgColor = SKYBLUE;

	if (player)
	{
		bgColor = (player->GetIsReverseGravity()) ? BLACK : SKYBLUE;
	}

	if (damage > 3)
		setcolor(RED, bgColor);
	
	else
		setcolor(YELLOW, bgColor);

	cout << "¡Ü";
}