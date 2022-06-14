#pragma once
#include "Scene.h"
#include "Core.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

public:
	void SetCurrentScene(Scene* scene);

	Scene* GetCurrentScene()
	{
		return curScene;
	}

	void Update()
	{
		curScene->Update();
	}

	void Release()
	{
		curScene->ReleaseScene();
	}

private:
	Scene* curScene;
	long timeScale = 210;
public:
	static SceneManager* sceneManager;

public:
	void SetTimeScale(long  t) { timeScale = t; }
	long GetTimeScale() { return timeScale; }
};

