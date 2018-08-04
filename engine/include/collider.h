#pragma once
#include "drawable.h"
namespace CollisionType
{
	enum ctypes
	{
		Tank, Projectile, Wall
	};
}

class Collider : public Drawable
{
protected:
	int ctype;
public:
	Collider(const char* _image, int layer);
	Collider(int w, int h, int layer);
	static void do_collision();
	int get_ctype();
	~Collider();

protected:
	virtual void receive_collision(Collider* other) = 0;
};
