#pragma once
#include "Item.h"

class Gravity : public Item
{
public:
	Gravity();
	Gravity(POSITION position);
	virtual ~Gravity();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);
	
private:
	void SetPlayerGravity(bool isGravity);
};