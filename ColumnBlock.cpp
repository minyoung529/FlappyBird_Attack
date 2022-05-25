#include "ColumnBlock.h"
#include "Core.h"

ColumnBlock::ColumnBlock() : Object({}, COLUMN)
{
}

ColumnBlock::ColumnBlock(POSITION position) : Object(position, COLUMN)
{
}

ColumnBlock::~ColumnBlock()
{
}

void ColumnBlock::Init()
{
}

void ColumnBlock::Update(char posOnBoard)
{
	position.x -= 1;

	if (position.x == -1)
	{
		isDead = true;
	}
}