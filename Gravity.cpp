#include "Gravity.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Player.h"

Gravity::Gravity()
{
}

Gravity::Gravity(POSITION position)
{
}

Gravity::~Gravity()
{
	SetPlayerGravity(false);
}

void Gravity::Init()
{
	SetPlayerGravity(true);
}

void Gravity::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
}

void Gravity::Render(int offsetX, int offsetY)
{
}

void Gravity::SetPlayerGravity(bool isGravity)
{
	GameScene* scene =
		dynamic_cast<GameScene*>(SceneManager::sceneManager->GetCurrentScene());

	Player* player =
		dynamic_cast<Player*>(scene->FindObjectOfType(BLOCK_TYPE::PLAYER));

	player->SetIsReverseGravity(isGravity);
}