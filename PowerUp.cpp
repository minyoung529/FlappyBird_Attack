#include "PowerUp.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Player.h"

PowerUp::PowerUp()
{
}

PowerUp::PowerUp(POSITION position)
{
}

PowerUp::~PowerUp()
{
	SetPlayerPower(false);
}

void PowerUp::Init()
{
	SetPlayerPower(true);
}

void PowerUp::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
}

void PowerUp::Render(int offsetX, int offsetY)
{
}

void PowerUp::SetPlayerPower(bool isPowerUp)
{
	GameScene* scene =
		dynamic_cast<GameScene*>(SceneManager::sceneManager->GetCurrentScene());

	Player* player =
		dynamic_cast<Player*>(scene->FindObjectOfType(BLOCK_TYPE::PLAYER));

	player->SetIsStrong(isPowerUp);
}
