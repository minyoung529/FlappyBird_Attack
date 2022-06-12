#pragma once
#include"Scene.h"
#include"Core.h"

class HelpScene : public Scene
{
public:
	HelpScene();
	virtual ~HelpScene();

public:
	virtual void Init();
	virtual void Update();
	virtual void ReleaseScene();

private:
	wchar_t title[6][81]
	{
		 L"██╗  ██╗███████╗██╗     ██████╗ ",
		 L"██║  ██║██╔════╝██║     ██╔══██╗",
		 L"███████║█████╗  ██║     ██████╔╝",
		 L"██╔══██║██╔══╝  ██║     ██╔═══╝ ",
		 L"██║  ██║███████╗███████╗██║	   ",
		 L"╚═╝  ╚═╝╚══════╝╚══════╝╚═╝	   "
	};

	const char* helps[8]
	{
		"▶ 스페이스(Space)로 플래피 버드를 날게 하세요!",
		"  ▶ 땅에 닿거나, 너무 높게 날거나, 기둥에 부딪히면 죽습니다!",

		"▶ 쉬프트(Shift)를 눌러 고양이를 쏘세요!",
		"  ▶ 고양이의 눈을 정확하게 쏴야 합니다!",

		"▶ 다양한 아이템을 먹어보세요!",
		"  ->  ▼	| 슬로우	| 세상이 느려집니다",
		"  ->  □	| 중력붕괴	| 중력의 방향이 바뀝니다.",
		"  ->  ♬	| 자양강장제	| 총알의 세기가 세집니다."
	};
};