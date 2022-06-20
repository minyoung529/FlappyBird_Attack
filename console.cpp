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
	// ������ 0000 0000 nnnn 0000 (�׷��� << 4 ����)
	// ���ڻ��� 0000 0000 0000 nnnn
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

// MCI_NOTIFY

void playsound(LPCWSTR name)
{
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, NULL);

	openEffect.lpstrElementName = name;
	openEffect.lpstrDeviceType = L"waveaudio";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&openEffect);
	// (DWORD)(LPVOID) equals DWORD_PTR, less safevb 

	dwID2 = openEffect.wDeviceID;
	mciSendCommand(dwID2, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playEffect);
}

void playbgm()
{
	openBGM.lpstrElementName = L"Data/BGM.wav";
	openBGM.lpstrDeviceType = L"waveaudio";

	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&openBGM);
	// (DWORD)(LPVOID) equals DWORD_PTR, less safevb 

	dwID = openBGM.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playBGM);
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