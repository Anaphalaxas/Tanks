#pragma once
#include "weapon.h"
#include "slug.h"
class Howitzer : public Weapon
{
private:
	const int total_fire_cooldown = 50;
public:
	Howitzer();
	void fire(float x, float y, float rotation, float barrel_length);
};