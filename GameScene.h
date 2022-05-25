#pragma once
#include"Scene.h"
#include"Core.h"
#include"Column.h"
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

private:
	void Draw();
	void DeleteObject();

private:
	int map[MAX_Y][MAX_X] = {EMPTY, };
	Player* player;
	vector<Object*> curSceneObjects;
};