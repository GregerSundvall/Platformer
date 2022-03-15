#include "player.h"
#include "engine.h"
#include "game.h"

void Player::update()
{
	// move
	if (keys[SDL_SCANCODE_D])
		x += 200 * delta_time;
	if (keys[SDL_SCANCODE_A])
		x -= 200 * delta_time;
	if (keys[SDL_SCANCODE_W])
		y -= 200 * delta_time;
	if (keys[SDL_SCANCODE_S])
		y += 200 * delta_time;


}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	SDL_Rect rect = { (int)x - (w/2), (int)y, w, h};
	SDL_RenderFillRect(render, &rect);
}
