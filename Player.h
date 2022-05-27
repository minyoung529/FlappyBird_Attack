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
	virtual void Render(int offsetX, int offsetY);
	static int GetScore() { return score; }
	static void AddScore(int sc) { score += sc; }

private:
	void CheckDead(char posOnBoard);
	static int score;
};