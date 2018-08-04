#pragma once
#include "tickable.h"
#include <string>
class Weapon : public Tickable
{
protected:
	std::string weapon_name;
	bool can_expire;
	int ttl;
	int original_ttl;
	bool currently_hijacking;
	int remaining_fire_cooldown;
	bool hijacks;
public:
	std::string get_weapon_name();
	int get_remaining_ticks();
	bool is_time_up();
	bool is_currently_hijacking();
	bool weapon_can_expire();
	void tick();
	virtual void fire(float x, float y, float rotation, float barrel_length) = 0;
	bool hijacks_input();
	Weapon();
};
