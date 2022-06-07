#pragma once
#include "Item.h"

class Slow : public Item
{
public:
	Slow();
	Slow(POSITION position);
	virtual ~Slow();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);
	virtual void Reset();
};