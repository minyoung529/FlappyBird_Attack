#pragma once
#include "Core.h"

class Object
{
public:
	Object() {}
	Object(POSITION position) : position(position), isDead(false) {}
	Object(POSITION position, char objectType)
		: position(position)
		, objectType(objectType)
		, isDead(false) {}

	Object(POSITION position, char objectType, int color)
		: position(position)
		, objectType(objectType)
		, isDead(false)
		, color(color) {}


	virtual ~Object() {}

public:
	virtual void Init() = 0;
	virtual void Update(char posOnBoard) = 0;

public:
	POSITION GetPosition() { return position; }
	char GetObjectType() { return objectType; }
	bool GetIsDead() { return isDead; }

protected:
	POSITION position;
	char objectType;
	bool isDead = false;
	int color;
};