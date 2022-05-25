#include "Column.h"
#include "Core.h"
#include "ColumnBlock.h"
#include <time.h>

void GenerateColumn(vector<Object*>& objects)
{
	srand((unsigned int)time(NULL));

	int random = (rand() % (MAX_Y - OPEN_COUNT - 1));
	++random;

	for (int y = 0; y < MAX_Y - 1; y++)
	{
		if (y >= random && y <= random + OPEN_COUNT - 1)
			continue;

		Object* block = new ColumnBlock({ MAX_X - 1, y });
		block->Init();

		objects.push_back(block);
	}
}