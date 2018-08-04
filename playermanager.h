#pragma once
#include "flowmanager.h"
#include "player.h"
#include <map>
#include <stdio.h>
class PlayerManager
{
private:
	int player_id_counter;
	static PlayerManager* instance;
	std::map<int, Player*> players;
public:
	static PlayerManager* get_instance();
	static void destroy();
	PlayerManager();
	~PlayerManager();
	Player* get_by_id(int id);
	void handle_input(int key);
	void check_for_round_end();
	void handle_end_round();
	void handle_pre_round();
	int create_player(Tank* t, int left, int right, int up, int down, int fire);
	int get_player_count();
};