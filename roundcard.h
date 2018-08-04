#pragma once
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include "display.h"
#include "drawable.h"

class RoundCard : public Drawable
{
private:
	ALLEGRO_FONT *font;
	int ttl;
public:
	RoundCard(int round);
	int get_ttl();
	void tick();
};
