#include "projectile.h"
std::unordered_set<Projectile*> Projectile::shots_fired;

void Projectile::tick()
{
	if (x < 0 || x > Display::PLAYABLE_WIDTH || y < 0 || y > Display::PLAYABLE_HEIGHT)
	{
		ttl = 0;
	}

}
bool Projectile::ttl_up()
{
	return (ttl <= 0);
}
void Projectile::add_lock()
{
	locks++;
}
void Projectile::remove_lock()
{
	locks--;
}
void Projectile::check_bullets()
{
	for (auto it = shots_fired.begin(); it != shots_fired.end();)
	{
		Projectile* p = *it;
		if (p->is_dead())
		{
			it = shots_fired.erase(it);
			delete p;
			continue;
		}
		it++;
	}
}

void Projectile::end_round()
{
	while (shots_fired.size() > 0)
	{
		Projectile* p = *shots_fired.begin();
		shots_fired.erase(shots_fired.begin());
		delete p;
	}
}
Projectile::Projectile(const char* _image) : Collider(_image, 1)
{
	has_done_end_of_life = false;
	shots_fired.insert(this);
}

Projectile::~Projectile()
{
}

bool Projectile::is_dead()
{
	return (has_done_end_of_life && locks <= 0);
}

void Projectile::receive_collision(Collider* other)
{
	fprintf(stdout, "BULLET OW\n");
	ttl = 0;
	end_of_life();
}