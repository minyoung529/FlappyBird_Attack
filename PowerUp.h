#pragma once
#include "Item.h"

class PowerUp : public Item
{
public:
	PowerUp();
	PowerUp(POSITION position);
	virtual ~PowerUp();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	void SetPlayerPower(bool isPowerUp);
};