#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(POSITION position, int damage);
	virtual ~Bullet();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

private:
	int damage = 0;
};