#pragma once
#include "Object.h"

class Player;

class Monster : public Object
{
public:
	Monster();
	Monster(POSITION position, Player* player);
	virtual ~Monster();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	Player* player;
};