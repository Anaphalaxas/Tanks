#include "slug.h"
Slug::Slug(float x, float y, float rotation, float barrel_length) : Projectile("resources/slug.bmp")
{
	ctype = CollisionType::Projectile;
	locks = 0;
	ttl = 100;
	muzzle_velocity = 10.0;
	float x_offset = sin(rotation)*barrel_length;
	float y_offset = cos(rotation)*barrel_length*-1.0;
	x_vel = sin(rotation)*muzzle_velocity;
	y_vel = cos(rotation)*muzzle_velocity*-1.0;
	this->rotation = rotation;
	cx = 3;
	cy = 4;
	this->x = x + x_offset;
	this->y = y + y_offset;
}
void Slug::end_of_life()
{
	has_done_end_of_life = true;
}

Slug::~Slug()
{
}
void Slug::tick()
{
	Projectile::tick();
	y += y_vel;
	x += x_vel;
	ttl--;

	if (ttl <= 0)
	{
		return end_of_life();
	}
}

void Slug::rotate(float amount)
{
	rotation += amount;
	float velocity = sqrt(x_vel * x_vel + y_vel * y_vel);
	x_vel = sin(rotation) * velocity;
	y_vel = cos(rotation) * velocity*-1.0;
}