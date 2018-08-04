#include "howitzer.h"
Howitzer::Howitzer()
{
	ttl = 0;
	can_expire = false;
	weapon_name = "Howitzer";
}

void Howitzer::fire(float x, float y, float rotation, float barrel_length)
{
	if (remaining_fire_cooldown == 0)
	{
		new Slug(x, y, rotation, barrel_length);
		remaining_fire_cooldown = total_fire_cooldown;
	}
}
