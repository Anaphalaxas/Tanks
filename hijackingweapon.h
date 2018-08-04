#pragma once
#include "weapon.h"
class HijackingWeapon : public Weapon
{
public:
	bool is_currently_hijacking();
	HijackingWeapon();
	virtual void handle_left() = 0;
	virtual void handle_right() = 0;
	virtual void handle_up() = 0;
	virtual void handle_down() = 0;
	virtual void handle_fire() = 0;
};
