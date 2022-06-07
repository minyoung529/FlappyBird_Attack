#include "Slow.h"
#include "SceneManager.h"

Slow::Slow()
{
}

Slow::Slow(POSITION position)
{
}

Slow::~Slow()
{
}

void Slow::Init()
{
	SceneManager::sceneManager->SetTimeScale(500);
}

void Slow::Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X])
{
}

void Slow::Render(int offsetX, int offsetY)
{
}

void Slow::Reset()
{
	SceneManager::sceneManager->SetTimeScale(250);
}