#include "roundcard.h"
RoundCard::RoundCard(int round) : Drawable(Display::SCREEN_WIDTH, Display::SCREEN_HEIGHT, 10)
{
	ttl = 180;
	x = 0;
	y = 0;
	cx = 0;
	cy = 0;
	rotation = 0;
	font = al_load_ttf_font("resources/arial.ttf", 32, 0);
	if (!font) { fprintf(stderr, "Could not load 'arial.ttf'.\n"); }
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	char buf[12];
	snprintf(buf, 12, "Round %i", round);
	al_draw_text(font, al_map_rgb(255, 0, 0), Display::SCREEN_WIDTH / 2, Display::SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, buf);
	al_set_target_bitmap(al_get_backbuffer(Display::get_instance()->get_display()));
}

void RoundCard::tick()
{
	ttl--;
}

int RoundCard::get_ttl()
{
	return ttl;
}