#pragma once

struct Player
{
	float x = 100.f;
	float y = 100.f;

	float velocity_x = 0.f;
	float velocity_y = 0.f;


	bool is_alive = true;

	float shoot_timer = 0.f;
	int next_projectile_index = 0;

	bool step(float dx, float dy);
	bool sweep(float dx, float dy);

	void update();
	void draw();
};
