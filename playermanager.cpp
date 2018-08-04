#include "playermanager.h"
PlayerManager* PlayerManager::instance = 0;
PlayerManager* PlayerManager::get_instance()
{
	if (!instance)
	{
		instance = new PlayerManager;
	}
	return instance;
}

int PlayerManager::get_player_count()
{
	return player_id_counter;
}
void PlayerManager::destroy()
{
	if (instance) delete instance;
}

PlayerManager::PlayerManager()
{
	player_id_counter = 0;
	players.clear();
}

PlayerManager::~PlayerManager()
{
	for (std::map<int, Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		delete it->second;
	}
}

int PlayerManager::create_player(Tank* t, int left, int right, int up, int down, int fire)
{
	Player* new_player = new Player(player_id_counter, t, left, right, up, down, fire);
	players.insert(std::pair<int, Player*>(player_id_counter, new_player));
	++player_id_counter;
	return player_id_counter - 1;
}

void PlayerManager::handle_input(int key)
{
	for (std::map<int, Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		if (it->second->is_alive() && it->second->handleInput(key) == 1)
		{
			break;
		}
	}
}

void PlayerManager::check_for_round_end()
{
	int alive_players = 0;
	for (std::map<int, Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		if (it->second->is_alive())
		{
			alive_players++;
			if (alive_players > 1) return;
		}
	}
	FlowManager::get_instance()->alert_players_dead();
}

void PlayerManager::handle_end_round()
{
	for (std::map<int, Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		if (it->second->is_alive())
		{
			it->second->add_point();
		}
	}
	FlowManager::get_instance()->post_round_logic_done();
}

void PlayerManager::handle_pre_round()
{
	for (std::map<int, Player*>::iterator it = players.begin(); it != players.end(); ++it)
	{
		it->second->pre_round_reset();
	}
	FlowManager::get_instance()->pre_round_logic_done();
}

Player* PlayerManager::get_by_id(int id)
{
	try { return players.at(id); }
	catch (const std::out_of_range &e)
	{
		e.what(); // just to avoid the 'unused variable' warning.
		fprintf(stderr, "PlayerManager received request for unknown player id %i\n", id);
		return 0;
	}
}