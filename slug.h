#pragma once
#include "projectile.h"
#include "drawable.h"
#include <cstdlib>
#include <math.h>
class Slug : public Projectile
{
public:
	void end_of_life();
	void tick();
	void rotate(float amount);
	Slug(float x, float y, float rotation, float barrel_length);
	~Slug();
};
