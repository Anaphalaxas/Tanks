#include "hud.h"
HUD::HUD() : Drawable(Display::SCREEN_WIDTH, Display::SCREEN_HEIGHT - Display::PLAYABLE_HEIGHT, 2)
{
	y = Display::PLAYABLE_HEIGHT;
	x = 0;
	cx = 0;
	cy = 0;
	weapons.clear();
}

HUD::~HUD()
{
	for (std::map<int, WeaponHUD*>::iterator it = weapons.begin(); it != weapons.end(); it++)
	{
		WeaponHUD *hud = it->second;
		delete hud;
	}
}

void HUD::initialize()
{
	int player_count = PlayerManager::get_instance()->get_player_count();
	for (int x = 0; x < player_count; x++)
	{
		WeaponHUD *new_weapon = new WeaponHUD(x);
		new_weapon->set_x((Display::SCREEN_WIDTH - 40) / (float)player_count*x + 20 + new_weapon->get_cx());
		new_weapon->set_y(Display::PLAYABLE_HEIGHT + new_weapon->get_cy());
	}
}

void HUD::tick()
{
	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(180, 180, 180));
	al_set_target_bitmap(al_get_backbuffer(Display::get_instance()->get_display()));
}