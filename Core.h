#pragma once

SceneManager* sceneManager = nullptr;

#define MAX_X	20
#define MAX_Y	10

typedef struct position
{
	int x;
	int y;
}POSITION, LPOSITION;

#define	EMPTY	'0'
#define	PLAYER	'1'
#define	COLUMN	'2'
#define	SLOW	'3'
#define	GRAVITY	'4'
#define	BULLET	'5'
#define	POWERUP	'6'
#define	FLOOR	'7'

#define BLACK	0
#define WHITE	15
#define YELLOW	14
#define SKYBLUE	3
#define GREEN	10

#define IN_SCREEN(x,y)	x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y