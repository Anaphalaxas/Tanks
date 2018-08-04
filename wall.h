#pragma once
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include "collider.h"
#include "display.h"
#include <vector>
#include <random>
#include <ctime>
class Wall : public Collider
{
public:
	Wall(int w, int h, float x, float y, float cx, float cy, float rotation);
	void receive_collision(Collider* other);
	static void clear_walls();
	static void generate_walls(int top, int bottom, int left, int right, int wall_count);
};

static std::vector<Wall*> walls;
