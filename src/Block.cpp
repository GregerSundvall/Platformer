#include "Block.h"
#include <SDL/SDL_rect.h>
#include <SDL/SDL_render.h>
#include "engine.h"
#include "game.h"


void Block::draw()
{
	SDL_Rect rect = {(int)x - camera.x, (int)y - camera.y, 32, 32};
	SDL_SetRenderDrawColor(render, 209, 131, 79, 255);
	SDL_RenderFillRect(render, &rect);
}