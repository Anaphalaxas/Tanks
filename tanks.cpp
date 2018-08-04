#include "tanks.h"
void Tanks::pre_loop_logic()
{
	MapManager::get_instance()->set_map(new DefaultTerrain());
	Tank* t = new GreenTank(320, 400, 0);
	Tank* t2 = new GreenTank(320, 80, 3.14159265);
	PlayerManager::get_instance()->create_player(t, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_SPACE);
	PlayerManager::get_instance()->create_player(t2, ALLEGRO_KEY_A, ALLEGRO_KEY_D, ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_LSHIFT);
	hud = new HUD();
	hud->initialize();
	rc = 0;
}

void Tanks::round_logic()
{
	Projectile::check_bullets();
	PlayerManager::get_instance()->check_for_round_end();
}

void Tanks::handle_input(int key)
{
	PlayerManager::get_instance()->handle_input(key);
}

void Tanks::pre_round_logic()
{
	PlayerManager::get_instance()->handle_pre_round();
	std::srand(std::time(0));
	Wall::generate_walls(200, Display::PLAYABLE_HEIGHT - 200, 200, Display::PLAYABLE_WIDTH - 200, 2 + (std::rand() % 4));
	rc = new RoundCard(FlowManager::get_instance()->get_round());
}

void Tanks::pre_round_post_logic()
{
	if (rc && rc->get_ttl() > 0)
	{
		rc->tick();
	}
	if (rc && rc->get_ttl() <= 0)
	{
		delete rc;
		FlowManager::get_instance()->pre_round_complete();
	}
}

void Tanks::end_round_logic()
{
	PlayerManager::get_instance()->handle_end_round();
	Projectile::end_round();
	Wall::clear_walls();
	FlowManager::get_instance()->end_round_complete();
}

void Tanks::post_loop_logic()
{
	PlayerManager::destroy();
	MapManager::destroy();
	delete hud;
}