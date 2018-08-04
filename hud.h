#pragma once
#include "tickable.h"
#include "drawable.h"
#include "hud_weapon.h"
#include "playermanager.h"
#include <map>
class HUD : public Tickable, public Drawable
{
private:
	std::map<int, WeaponHUD*> weapons;
public:
	HUD();
	~HUD();
	void tick();
	void initialize();
};
