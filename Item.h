#pragma once
#include "Object.h"

class Item : public Object
{
public:
	Item();
	Item(POSITION position);
	Item(POSITION position, ITEM_TYPE itemType);
	virtual ~Item();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	ITEM_TYPE itemType;
	int timer = 0;
	bool isStart = false;
	Item* item;
};