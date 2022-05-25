#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void ReleaseScene() = 0;

protected:
	int updateTime = 0;
};