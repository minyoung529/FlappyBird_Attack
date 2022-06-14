#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Bullet;

class Player : public Object
{
public:
	Player();
	Player(POSITION position);
	virtual ~Player();

public:
	virtual void Init();
	virtual void Update(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	virtual void Render(int offsetX, int offsetY);

public:
	static int GetScore() { return score; }
	static void AddScore(int sc) { score += sc; }
	static int GetHighScore() { return highScore; }
	static void UpdateHighScore() { highScore = score; }

	void SetIsReverseGravity(bool isRV) { isReverseGravity = isRV; }
	bool GetIsReverseGravity() { return isReverseGravity; }
	void SetIsStrong(bool isSt) { isStrong = isSt; }

private:
	void CheckDead(BLOCK_TYPE posOnBoard[MAX_Y][MAX_X]);
	void DeleteObject();

private:
	static int score;
	static int highScore;
	vector<Bullet*> bullets;

#pragma region Item
	bool isReverseGravity;
	bool isStrong;
#pragma endregion

};