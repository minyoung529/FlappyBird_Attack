#pragma once
#include "Object.h"

class Player;

class Bullet : public Object
{
public:
	Bullet();
	Bullet(POSITION position, int damage, Player* player);
	virtual ~Bullet();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	int damage = 0;
	Player* player;
};