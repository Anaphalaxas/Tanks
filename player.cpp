#include "player.h"
int Player::get_score()
{
	return score;
}
void Player::add_point()
{
	score++;
}

void Player::pre_round_reset()
{
	tank->reset_position();
}

bool Player::is_alive()
{
	return !tank->is_dead();
}
std::string Player::get_weapon_info()
{
	return tank->get_weapon_info();
}
std::string Player::get_weapon_name()
{
	return tank->get_weapon_name();
}
std::string Player::get_weapon_time()
{
	return tank->get_weapon_time();
}
Player::Player(int _id, Tank* _tank, int left, int right, int forward, int reverse, int fire)
{
	player_id = _id;
	tank = _tank;
	controls = Controls(forward, reverse, left, right, fire);
	score = 0;
}

int Player::handleInput(int key)
{
	if (key == controls.get_fire())
	{
		this->fire();
		return 1;
	}
	if (key == controls.get_forward())
	{
		this->forward();
		return 1;
	}
	if (key == controls.get_left())
	{
		this->left();
		return 1;
	}
	if (key == controls.get_right())
	{
		this->right();
		return 1;
	}
	if (key == controls.get_reverse())
	{
		this->reverse();
		return 1;
	}
	return 0;
}

void Player::forward()
{
	tank->forward();
}

void Player::reverse()
{
	tank->reverse();
}

void Player::left()
{
	tank->turn_left();
}

void Player::right()
{
	tank->turn_right();
}

void Player::fire()
{
	tank->fire();
}

