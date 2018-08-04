#pragma once
#include "hijackingweapon.h"
#include "slug.h"
class FlyByWire : public HijackingWeapon
{
private:
	Slug* current_projectile;

public:
	FlyByWire();
	void fire(float x, float y, float rotation, float barrel_length);
	void handle_left();
	void handle_right();
	void handle_up();
	void handle_down();
	void handle_fire();
	void tick();
};
