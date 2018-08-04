#pragma once


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <math.h>
#include <stdio.h>
#include <unordered_set>

#include "display.h"
#include "collider.h"
#include "flybywire.h"
#include "howitzer.h"
#include "hijackingweapon.h"
#include "mapmanager.h"
#include "slug.h"
#include "tickable.h"
#include "weapon.h"
#include "wall.h"
#include "sat.h"
static const float PI = 3.141592653589793;

class Tank : public Collider, public Tickable
{
private:
	float init_x;
	float init_y;
	float init_rotation;
	float x_vel;
	float y_vel;
	float barrel_length;
	float braking_speed;
	float acceleration_speed;
	float turn_speed;
	float max_speed;
	void decelerate();
	bool alive;
	Weapon* current_weapon;

public:
	Tank(float _x, float _y, float _rotation, const char* _image);
	~Tank();
	void reset_position();
	void accelerate(float x_acc, float y_acc);
	float get_x_pos();
	float get_y_pos();
	float get_rotation();
	float get_x_vel();
	float get_y_vel();
	float get_barrel_length();
	float get_acceleration_speed();
	float get_braking_speed();
	float get_turn_speed();
	void forward();
	void reverse();
	void turn_left();
	void turn_right();
	void fire();
	void tick();
	bool is_dead();
	std::string get_weapon_name();
	std::string get_weapon_time();
	std::string get_weapon_info();
	ALLEGRO_BITMAP* get_image();
	void turn(float amount);
	void receive_collision(Collider* other);
};
