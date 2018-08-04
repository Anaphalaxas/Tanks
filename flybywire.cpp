#include "flybywire.h"
#include "hijackingweapon.h"
#include "slug.h"
FlyByWire::FlyByWire()
{
	weapon_name = "Fly-By-Wire";
	can_expire = true;
	original_ttl = 1000;
	ttl = original_ttl;
}
void FlyByWire::tick()
{
	Weapon::tick();
	if (current_projectile && current_projectile->ttl_up())
	{
		current_projectile->remove_lock();
		current_projectile = 0;
		currently_hijacking = false;
	}
}
void FlyByWire::fire(float x, float y, float rotation, float barrel_length)
{
	if (current_projectile) return;
	current_projectile = new Slug(x, y, rotation, barrel_length);
	current_projectile->add_lock();
	currently_hijacking = true;

}
void FlyByWire::handle_down()
{

}

void FlyByWire::handle_up()
{

}

void FlyByWire::handle_fire()
{

}

void FlyByWire::handle_left()
{
	current_projectile->rotate(-0.1);
}

void FlyByWire::handle_right()
{
	current_projectile->rotate(0.1);
}