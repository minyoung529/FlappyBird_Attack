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
	virtual void Update(char posOnBoard);
};

