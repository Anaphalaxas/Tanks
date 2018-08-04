#pragma once

#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>

#include "display.h"
#include "drawable.h"
#include "tickable.h"
#include "playermanager.h"
class WeaponHUD : public Tickable, public Drawable
{
private:
	int player_id;
	ALLEGRO_FONT *font;
public:
	WeaponHUD(int player_id);
	~WeaponHUD();
	void tick();
};
