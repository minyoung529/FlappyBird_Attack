#pragma once
#define MAX_X	20
#define MAX_Y	10

typedef struct position
{
	int x;
	int y;
}POSITION, LPOSITION;

enum class BLOCK_TYPE
{
	EMPTY	,
	PLAYER	,
	COLUMN	,
	SLOW	,
	GRAVITY	,
	BULLET	,
	POWERUP	,
	FLOOR	,
	MONSTER
};

enum class ITEM_TYPE
{
	NONE	,
	SLOW	,
	POWERUP ,
	GRAVITY ,
	COUNT
};


#define BLACK		0
#define WHITE		15
#define YELLOW		14
#define SKYBLUE		3
#define GREEN		10
#define RED			12
#define LIGHTYELLOW 14

#define PLAYER_X	2

#define IN_SCREEN(x,y)	x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y

#define OFFSET_X	75
#define OFFSET_Y	20

#define	FRAME_SIZE_X	MAX_X+8
#define	FRAME_SIZE_Y	MAX_Y+6