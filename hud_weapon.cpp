#include "hud_weapon.h"
WeaponHUD::WeaponHUD(int player_id) : Drawable(150, 40, 3)
{
	cx = 75;
	cy = 20;
	rotation = 0;
	x = 0;
	y = 0;
	this->player_id = player_id;
	font = al_load_ttf_font("resources/arial.ttf", 16, 0);
	if (!font) { fprintf(stderr, "Could not load 'arial.ttf'.\n"); }

}

WeaponHUD::~WeaponHUD()
{

}

void WeaponHUD::tick()
{
	Player *player = PlayerManager::get_instance()->get_by_id(player_id);
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
	char buf[15];
	snprintf(buf, 15, "Player %i: %i", player_id + 1, player->get_score());
	al_draw_text(font, al_map_rgb(20, 20, 20), 75, 0, ALLEGRO_ALIGN_CENTER, buf);
	al_draw_text(font, al_map_rgb(20, 20, 20), 75, 20, ALLEGRO_ALIGN_CENTER, player->get_weapon_info().c_str());
	al_set_target_bitmap(al_get_backbuffer(Display::get_instance()->get_display()));
}