#pragma once
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

#include <io.h>
#include <fcntl.h>

#include "resource.h"
using namespace std;

void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);
void fullscreen();
void cursorview();
void playsound(int sound);