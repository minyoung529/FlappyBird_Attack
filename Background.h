#pragma once
#include "Core.h"

#define	FRAME_SIZE_X	MAX_X+8
#define	FRAME_SIZE_Y	MAX_Y+6

void DrawFrame();
void DrawCrossButton(int x, int y);
void DrawJoyStick(int x, int y, int color);