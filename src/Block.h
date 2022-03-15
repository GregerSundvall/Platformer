#pragma once
#include "collision.h"



struct Block
{
	float x;
	float y;

	AABB getCollision() { return {x, y, x + 32, y + 32}; }
	void draw();
};