#pragma once
#include"Core.h"
#include"Column.h"
#include"Scene.h"
#include<vector>
using namespace std;

class Player;
class Object;
class Monster;

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void ReleaseScene();

public:
	BLOCK_TYPE GetPosition(POSITION position)
	{
		return map[position.y][position.x];
	}

public:
	Player* GetPlayer() { return player; }

private:
	void Draw();
	void DeleteObject();
	void DrawNumber();

private:
	BLOCK_TYPE map[MAX_Y][MAX_X] = { BLOCK_TYPE::EMPTY, };
	Player* player;
	Monster* monster;
	vector<Object*> currentObjects;
	bool isRelease = false;

	const char* numbers[7]
	{
		" _______    ____   _______  _______  _   ___  _______  ___      _______   _____   _______ ",
		"|  _    |  |    | |       ||       || | |   ||       ||   |    |       | |  _  | |  _    |",
		"| | |   |   |   | |____   ||___    || |_|   ||   ____||   |___ |___    | | |_| | | | |   |",
		"| | |   |   |   |  ____|  | ___|   ||       ||  |____ |    _  |    |   ||   _   || |_|   |",
		"| |_|   |   |   | | ______||___    ||___    ||_____  ||   | | |    |   ||  | |  ||___    |",
		"|       |   |   | | |_____  ___|   |    |   | _____| ||   |_| |    |   ||  |_|  |    |   |",
		"|_______|   |___| |_______||_______|    |___||_______||_______|    |___||_______|    |___|"
	};
};