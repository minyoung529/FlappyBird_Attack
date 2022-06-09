#include "Background.h"
#include "console.h"
#include <math.h>

void DrawFrame()
{
	int absX = abs(MAX_X - FRAME_SIZE_X);
	int yPoses[] = { OFFSET_Y - (FRAME_SIZE_Y - MAX_Y), OFFSET_Y + FRAME_SIZE_Y };

	setcolor(WHITE, WHITE);

	for (int y : yPoses)
	{
		for (int x = -absX; x < FRAME_SIZE_X; x++)
		{
			gotoxy(OFFSET_X + x * 2, y);
			cout << "бс";
		}
	}

	for (int i = yPoses[0]; i <= yPoses[1]; i++)
	{
		gotoxy(OFFSET_X - absX * 2, i);
		cout << "l";

		gotoxy(OFFSET_X + FRAME_SIZE_X * 4 + 4, i);
		cout << "l";
	}

	int distance = 8;
	int start = -8;

	for (int i = start, count = 0; i < start + distance * 4; i += distance, count++)
	{
		if (count % 2 == 0)
			DrawCrossButton(OFFSET_X + i, OFFSET_Y + FRAME_SIZE_Y - 1);
		else
			DrawCrossButton(OFFSET_X + i, OFFSET_Y + FRAME_SIZE_Y - 2);
	}

	DrawJoyStick(OFFSET_X + MAX_X * 2, OFFSET_Y + FRAME_SIZE_Y - 1, RED);
	DrawJoyStick(OFFSET_X + MAX_X * 2 + 10, OFFSET_Y + FRAME_SIZE_Y - 1, SKYBLUE);
}

void DrawCrossButton(int x, int y)
{
	setcolor(SKYBLUE, SKYBLUE);
	gotoxy(x + 3, y - 3);
	cout << "бс";

	setcolor(RED, RED);
	gotoxy(x + 1, y - 2);
	cout << "бс";
	gotoxy(x + 5, y - 2);
	cout << "бс";

	setcolor(YELLOW, YELLOW);
	gotoxy(x + 3, y - 2);
	cout << "бс";

	setcolor(SKYBLUE, SKYBLUE);
	gotoxy(x + 3, y - 1);
	cout << "бс";
}

void DrawJoyStick(int x, int y, int color)
{
	for (int i = 2; i >= 1; i--)
	{
		setcolor(WHITE, WHITE);
		gotoxy(x - 5, y - i);
		cout << "|";
	}

	setcolor(color, color);

	gotoxy(x - 5, y - 3);
	cout << "бс";

	gotoxy(x - 7, y - 3);
	cout << "бс";

	gotoxy(x - 5, y - 4);
	cout << "бс";

	gotoxy(x - 7, y - 4);
	cout << "бс";
}