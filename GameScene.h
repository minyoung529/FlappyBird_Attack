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
	Object* FindObjectOfType(BLOCK_TYPE type);
	vector<Object*> FindObjectsOfType(BLOCK_TYPE type);

private:
	void Draw();
	void DeleteObject();

private:
	BLOCK_TYPE map[MAX_Y][MAX_X] = { BLOCK_TYPE::EMPTY, };
	Player* player;
	Monster* monster;
	vector<Object*> currentObjects;
	bool isRelease = false;
};