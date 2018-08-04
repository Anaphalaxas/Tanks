#pragma once
#include <allegro5\allegro.h>
#include <map>

class Drawable
{
public:
	Drawable(const char* _image, int layer);
	Drawable(int w, int h, int layer);
	~Drawable();
	float get_cx();
	float get_cy();
	float get_x();
	float get_y();
	int get_width();
	int get_height();
	float get_largest_dimension();
	float get_rotation();
	void set_x(float);
	void set_y(float);
	void get_bounding_box(std::pair<float, float>*);
	ALLEGRO_BITMAP* get_image();

	static std::multimap<int, void*> drawables;

protected:
	ALLEGRO_BITMAP* image;
	int layer;
	float cx;
	float cy;
	float x;
	float y;
	float rotation;
};

typedef std::multimap<int, void*>::iterator drawable_it;
