#include "wall.h"

Wall::Wall(int w, int h, float _x, float _y, float _cx, float _cy, float _rotation) : Collider(w, h, 2)
{
	x = _x;
	y = _y;
	cx = _cx;
	cy = _cy;
	rotation = _rotation;
	ctype = CollisionType::Wall;
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(100, 0, 100));
	ALLEGRO_COLOR outline = al_map_rgb(140, 0, 140);
	al_draw_line(0, 0, 0, h, outline, 1.0);
	al_draw_line(0, 0, w, 0, outline, 1.0);
	al_draw_line(w, h, 0, h, outline, 1.0);
	al_draw_line(w, h, w, 0, outline, 1.0);
	al_set_target_bitmap(al_get_backbuffer(Display::get_instance()->get_display()));
	walls.push_back(this);
}

void Wall::receive_collision(Collider* other)
{

}

void Wall::clear_walls()
{
	while (walls.size() > 0)
	{
		Wall *w = *walls.begin();
		walls.erase(walls.begin());
		delete w;
	}
}

void Wall::generate_walls(int top, int bottom, int left, int right, int wall_count)
{
	std::srand(std::time(0));
	for (int wc = 0; wc < wall_count; wc++)
	{
		int x = left + std::rand() % (right - left);
		int y = top + std::rand() % (bottom - top);
		int width = 50 + std::rand() % 200;
		int height = 8;
		float rotation = (std::rand() % 314) / 100.0;
		new Wall(width, height, x, y, width / 2, height / 2, rotation);
	}
}