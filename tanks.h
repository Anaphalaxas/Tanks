#pragma once
#include "default_terrain.h"
#include "green_tank.h"
#include "hud.h"
#include "mapmanager.h"
#include "playermanager.h"
#include "projectile.h"
#include "roundcard.h"
#include "tank.h"
class Tanks
{
private:
	RoundCard *rc;
	HUD *hud;
public:
	void pre_loop_logic();
	void round_logic();
	void handle_input(int key);
	void pre_round_logic();
	void pre_round_post_logic();
	void end_round_logic();
	void post_loop_logic();
};
