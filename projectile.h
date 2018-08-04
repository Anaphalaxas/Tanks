#pragma once
#include "collider.h"
#include <allegro5\allegro.h>
#include "tickable.h"
#include "display.h"
#include <unordered_set>
#include "weapon.h"
class Projectile : public Collider, public Tickable
{
protected:
	float x_vel;
	float y_vel;
	float muzzle_velocity;
	int ttl;
	int locks;
	int shooter_id;
	bool has_done_end_of_life;
	static std::unordered_set<Projectile*> shots_fired;
public:
	static void end_round();
	void add_lock();
	void remove_lock();
	bool is_dead();
	virtual void end_of_life() = 0;
	virtual void tick();
	Projectile(const char* _image);
	~Projectile();
	static void check_bullets();
	bool ttl_up();
	void receive_collision(Collider* other);
};
