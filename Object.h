#pragma once
#include "Core.h"

class Object
{
public:
	Object() :position{}, objectType(BLOCK_TYPE::EMPTY), isDead(false), color(WHITE){}

	Object(POSITION position) : position(position), objectType(BLOCK_TYPE::EMPTY), isDead(false), color(WHITE) {}

	Object(POSITION position, BLOCK_TYPE objectType)
		: position(position)
		, objectType(objectType)
		, isDead(false)
		, color(WHITE) {}

	Object(POSITION position, BLOCK_TYPE objectType, int color)
		: position(position)
		, objectType(objectType)
		, isDead(false)
		, color(color) {}


	virtual ~Object() {}

public:
	virtual void Init() = 0;
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]) = 0;
	virtual void Render(int offsetX, int offsetY) = 0;

public:
	POSITION GetPosition() { if (isDead)return POSITION{ 0,0, }; return position; }
	BLOCK_TYPE GetObjectType() { return objectType; }
	bool GetIsDead() { return isDead; }

protected:
	POSITION position;
	BLOCK_TYPE objectType;
	bool isDead = false;
	int color;
};