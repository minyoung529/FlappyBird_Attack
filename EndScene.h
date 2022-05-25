#pragma once
#include"Scene.h"
#include"Core.h"

class EndScene : public Scene
{
public:
	EndScene();
	virtual ~EndScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void ReleaseScene();
};