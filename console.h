#pragma once
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>
#include <Digitalv.h>

#include <io.h>
#include <fcntl.h>

#include "resource.h"


using namespace std;

static MCI_OPEN_PARMS openBGM;
static MCI_PLAY_PARMS playBGM;

static MCI_OPEN_PARMS openEffect;
static MCI_PLAY_PARMS playEffect;

static UINT dwID;
static UINT dwID2;

void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);
void fullscreen();
void cursorview();
void playsound(int sound);
void playbgm();
void stopbgm();
void changefont();