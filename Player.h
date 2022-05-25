#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	Player(POSITION position);
	virtual ~Player();

public:
	virtual void Init();
	virtual void Update(char posOnBoard);

private:
	void CheckDead(char posOnBoard);
};