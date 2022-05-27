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

public:
	static int GetScore() { return score; }
	static void AddScore(int sc) { score += sc; }
	static int GetHighScore() { return highScore; }
	static void UpdateHighScore() { highScore = score; }

private:
	void CheckDead(char posOnBoard);
	static int score;
	static int highScore;
};