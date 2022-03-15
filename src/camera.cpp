#include "camera.h"
#include "game.h"


void Camera::update()
{
	x = player.x - 400;
	y = player.y - 300;
}