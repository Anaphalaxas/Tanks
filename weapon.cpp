#include "weapon.h"
int Weapon::get_remaining_ticks()
{
	return ttl;
}
bool Weapon::weapon_can_expire()
{
	return can_expire;
}
std::string Weapon::get_weapon_name()
{
	return weapon_name;
}
bool Weapon::is_currently_hijacking()
{
	return currently_hijacking;
}
bool Weapon::hijacks_input()
{
	return hijacks;
}
Weapon::Weapon()
{
	hijacks = false;
	currently_hijacking = false;
	remaining_fire_cooldown = 0;
	ttl = 0;
	original_ttl = 0;
	can_expire = true;
}

void Weapon::tick()
{
	if (remaining_fire_cooldown > 0) remaining_fire_cooldown--;
	if (ttl > 0) ttl--;
}
bool Weapon::is_time_up()
{
	return ttl <= 0 && can_expire;
}
