#pragma once
#include "player.h"
#include "Block.h"
#include "camera.h"

#define MAP_COLS 16
#define MAP_ROWS 16
#define NUM_BLOCKS (MAP_COLS * MAP_ROWS)

extern Player player;
extern Block* blocks[NUM_BLOCKS];
extern Camera camera;

void loadMap();

