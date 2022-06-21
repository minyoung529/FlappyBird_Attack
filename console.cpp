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
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void playsound(int sound)
{
	PlaySound(MAKEINTRESOURCE(sound), NULL, SND_RESOURCE | SND_ASYNC);
}

void playbgm()
{
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, NULL);

	openBGM.lpstrElementName = L"Data/BGM.wav";
	openBGM.lpstrDeviceType = L"waveaudio";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&openBGM);
	// (DWORD)(LPVOID) equals DWORD_PTR, less safevb 

	dwID = openBGM.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBGM);
}

void stopbgm()
{
	mciSendCommand(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&openBGM);
}

void changefont()
{
	CONSOLE_FONT_INFOEX cfi = {};
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"NSimSun");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}