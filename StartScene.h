﻿#pragma once
#include"Scene.h"
#include"Core.h"

class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void ReleaseScene();

private:
	void RenderTitle();
	void RenderButton();
	void RenderBirds();

	void GetButton(const char* name, const char* key, int y);

private:
	int updateTime = 0;
	wchar_t title[6][81]
	{
		L"███████╗██╗      █████╗ ██████╗ ██████╗ ██╗   ██╗    ██████╗ ██╗██████╗ ██████╗ ",
		L"██╔════╝██║     ██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝    ██╔══██╗██║██╔══██╗██╔══██╗",
		L"█████╗  ██║     ███████║██████╔╝██████╔╝ ╚████╔╝     ██████╔╝██║██████╔╝██║  ██║",
		L"██╔══╝  ██║     ██╔══██║██╔═══╝ ██╔═══╝   ╚██╔╝      ██╔══██╗██║██╔══██╗██║  ██║",
		L"██║     ███████╗██║  ██║██║     ██║        ██║       ██████╔╝██║██║  ██║██████╔╝",
		L"╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝        ╚═╝       ╚═════╝ ╚═╝╚═╝  ╚═╝╚═════╝ "
	};

	const char* bird[3]
	{
		" ___\n",
		"/__⊙|_\n",
		"|___/-|"
	};
};