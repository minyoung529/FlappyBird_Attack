#pragma once
#include "Scene.h"

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
public:
	static SceneManager* sceneManager;
};

