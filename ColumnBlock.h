#pragma once
#include "Object.h"

class ColumnBlock : public Object
{
public:
	ColumnBlock();
	ColumnBlock(POSITION position);
	virtual ~ColumnBlock();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	bool isScorePlus;
};