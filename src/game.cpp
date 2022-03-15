#include "game.h"
#include "camera.h"

const char* LEVEL =
"................"
"................"
"................"
"................"
"................"
"........#######."
"................"
"................"
"..######........"
"................"
"............#..."
"......#######..."
"................"
"................"
"################"
"................";

Player player;
Block* blocks[NUM_BLOCKS] = {nullptr};
Camera camera;

void loadMap()
{
	const char* ptr = LEVEL;

	for (size_t y = 0; y < MAP_ROWS; y++)
	{
		for (int x = 0; x < MAP_COLS; ++x, ++ptr)
		{
			if (*ptr != '#')
			{
				continue;
			}
			Block* block = new Block;
			block->x = x * 32;
			block->y = y * 32;
			blocks[y * MAP_COLS + x] = block;
		}
	}
}
