#pragma once
#include "controls.h"
#include "tank.h"
#include <math.h>
class Player
{
private:
	Controls controls;
	Tank *tank;
	int score;
	int player_id;
public:
	std::string get_weapon_name();
	std::string get_weapon_time();
	std::string get_weapon_info();
	Player(int _id, Tank* _tank, int left, int right, int forward, int reverse, int fire);
	int handleInput(int key);
	void forward();
	void reverse();
	void left();
	void right();
	void fire();
	bool is_alive();
	void add_point();
	void pre_round_reset();
	int get_score();
};