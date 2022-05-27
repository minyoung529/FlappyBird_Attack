#pragma once
#include"Core.h"
#include"Column.h"
#include"Scene.h"
#include<vector>
using namespace std;

class Player;
class Object;

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
	char GetPosition(POSITION position)
	{
		return map[position.y][position.x];
	}

public:

private:
	void Draw();
	void DeleteObject();

private:
	int map[MAX_Y][MAX_X] = {EMPTY, };
	Player* player;
	vector<Object*> currentObjects;
	bool isRelease = false;
};