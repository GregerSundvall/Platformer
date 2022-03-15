#include "player.h"
#include "engine.h"
#include "game.h"

bool space_previous = false;

void Player::update()
{
	// move
	if (keys[SDL_SCANCODE_W])
		velocity_y -= 500.f * delta_time;
	if (keys[SDL_SCANCODE_A])
		velocity_x -= 500.f * delta_time;
	if (keys[SDL_SCANCODE_S])
		velocity_y += 500.f * delta_time;
	if (keys[SDL_SCANCODE_D])
		velocity_x += 500.f * delta_time;
	
	bool isGrounded = sweep(0.f, 1.5f);
	if (keys[SDL_SCANCODE_SPACE] && !space_previous && isGrounded)
	{
		velocity_y -= 1000.f;
	}
	space_previous = keys[SDL_SCANCODE_SPACE];

	// Apply gravity
	velocity_y += 1000.f * delta_time;

	// Apply friction
	velocity_x -= velocity_x * 2.5f * delta_time;
	velocity_y -= velocity_y * 2.5f * delta_time;

	// Apply velocity to position
	if (!step(velocity_x * delta_time, 0.f))
	{
		velocity_x = -velocity_x * 0.5f;
	}
	if (!step(0.f, velocity_y * delta_time))
	{
		velocity_y = -velocity_y * 0.5f;
	}
}

bool Player::step(float dx, float dy)
{
	if (sweep(dx, dy))
	{
		return false; // Reverts sweep response!
	}

	x += dx;
	y += dy;
	return true;
}


bool Player::sweep(float dx, float dy)
{
	// Boundaries check
	//if (x + dx < 16 || x + dx > 800 - 16 ||
	//	y + dy < 16 || y + dy > 600 - 16)
	//{
	//	return true;
	//}

	AABB player_box = AABB::make_from_position_size(x +dx, y + dy, 32, 32);
	for (size_t i = 0; i < NUM_BLOCKS; i++)
	{
		Block* block = blocks[i];
		if (block == nullptr)
		{
			continue;
		}
		if (aabb_intersect(player_box, block->getCollision()))
		{
			return true;
		}
	}

	return false;
}

void Player::draw()
{
	SDL_SetRenderDrawColor(render, 150, 25, 40, 255);
	SDL_Rect rect = { (int)x -16 - camera.x, (int)y -16 - camera.y, 32, 32};
	SDL_RenderFillRect(render, &rect);
}
