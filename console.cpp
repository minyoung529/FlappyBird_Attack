#include "console.h"

void gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void setcolor(int color, int bgcolor)
{
	// 배경색은 0000 0000 nnnn 0000 (그래서 << 4 해줌)
	// 글자색은 0000 0000 0000 nnnn
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void cursorview()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(hOut, &info);
}

void playsound(int sound)
{
	PlaySound(MAKEINTRESOURCE(sound), NULL, SND_RESOURCE | SND_ASYNC);
}
