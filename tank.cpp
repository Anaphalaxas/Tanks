#include "tank.h"
ALLEGRO_BITMAP* Tank::get_image() { return image; }

Tank::Tank(float _x, float _y, float _rotation, const char* _image) : Collider(_image, 1)
{
	ctype = CollisionType::Tank;
	alive = true;
	current_weapon = new FlyByWire();
	max_speed = 1.06;
	acceleration_speed = 0.1;
	braking_speed = 0.08;
	turn_speed = 0.05;
	x = _x;
	y = _y;
	init_x = _x;
	init_y = _y;
	cx = 24;
	cy = 38;
	rotation = _rotation;
	init_rotation = _rotation;
	x_vel = 0.0;
	y_vel = 0.0;
	// Default barrel length
	barrel_length =40.0;
}
void Tank::reset_position()
{
	x = init_x;
	y = init_y;
	rotation = init_rotation;
	x_vel = 0.0;
	y_vel = 0.0;
	if (current_weapon) delete current_weapon;
	current_weapon = new Howitzer();
	alive = true;
}
Tank::~Tank()
{
	al_destroy_bitmap(image);
}
std::string Tank::get_weapon_name()
{
	return current_weapon->get_weapon_name();
}
std::string Tank::get_weapon_time()
{
	if (!current_weapon->weapon_can_expire()) return "";
	float seconds = (float)current_weapon->get_remaining_ticks() / (float)Display::FPS;
	char ret[8];
	snprintf(ret, 8, "%.2fs", seconds);
	return std::string(ret);
}

std::string Tank::get_weapon_info()
{
	std::string first = get_weapon_name();
	std::string second = get_weapon_time();
	if (second == "") return first;
	return first + ": " + second;
}
float Tank::get_x_pos() { return x; }
float Tank::get_y_pos() { return y; }
float Tank::get_rotation() { return rotation; }
float Tank::get_x_vel() { return x_vel; }
float Tank::get_y_vel() { return y_vel; }
float Tank::get_barrel_length() { return barrel_length; }
float Tank::get_acceleration_speed() { return acceleration_speed; }
float Tank::get_braking_speed() { return braking_speed; }
float Tank::get_turn_speed() { return turn_speed; }
void Tank::turn(float amount)
{
	rotation += amount;
}

void Tank::accelerate(float x_acc, float y_acc)
{
	x_vel += x_acc;
	y_vel += y_acc;
	float intended_speed = sqrt(powf(x_vel, 2) + powf(y_vel, 2));
	if (intended_speed > max_speed)
	{
		float ratio = max_speed / intended_speed;
		x_vel *= ratio;
		y_vel *= ratio;
		// ratio * x = 30
		// ratio = 30 / x
	}
}

void Tank::turn_left()
{
	if (current_weapon->hijacks_input() && current_weapon->is_currently_hijacking())
	{
		HijackingWeapon* wep = dynamic_cast<HijackingWeapon*>(current_weapon);
		return wep->handle_left();
	}
	turn(turn_speed*-1.0);
}

void Tank::turn_right()
{
	if (current_weapon->hijacks_input() && current_weapon->is_currently_hijacking())
	{
		HijackingWeapon* wep = dynamic_cast<HijackingWeapon*>(current_weapon);
		return wep->handle_right();
	}
	turn(turn_speed);
}

void Tank::forward()
{
	if (current_weapon->hijacks_input() && current_weapon->is_currently_hijacking())
	{
		HijackingWeapon* wep = dynamic_cast<HijackingWeapon*>(current_weapon);
		return wep->handle_up();
	}
	float x_acc = sin(rotation) * acceleration_speed;
	float y_acc = cos(rotation) * acceleration_speed * -1.0;
	this->accelerate(x_acc, y_acc);
}

void Tank::reverse()
{
	if (current_weapon->hijacks_input() && current_weapon->is_currently_hijacking())
	{
		HijackingWeapon* wep = dynamic_cast<HijackingWeapon*>(current_weapon);
		return wep->handle_down();
	}
	float x_acc = sin(rotation) * braking_speed * -1.0;
	float y_acc = cos(rotation) * braking_speed;
	this->accelerate(x_acc, y_acc);
}

void Tank::fire()
{
	if (current_weapon->hijacks_input() && current_weapon->is_currently_hijacking())
	{
		HijackingWeapon* wep = dynamic_cast<HijackingWeapon*>(current_weapon);
		return wep->handle_fire();
	}
	current_weapon->fire(x, y, rotation, barrel_length);
}

void Tank::decelerate()
{
	float cof = MapManager::get_instance()->get_current_map()->get_cof();
	x_vel *= (1 - cof);
	y_vel *= (1 - cof);
	if (abs(x_vel) < 0.001) x_vel = 0.0;
	if (abs(y_vel) < 0.001) y_vel = 0.0;
}

void Tank::tick()
{
	if (current_weapon->is_time_up())
	{
		delete current_weapon;
		current_weapon = new Howitzer();
	}
	x += x_vel;
	y += y_vel;
	this->decelerate();
}

void Tank::receive_collision(Collider* other)
{
	if (other->get_ctype() == CollisionType::Projectile)
	{
		fprintf(stdout, "OW\n");
		alive = false;
		x = -500;
		y = -500;
	}
	else if (other->get_ctype() == CollisionType::Wall)
	{
		/*
		Wall *w = dynamic_cast<Wall*>(other);

		std::pair<float, float> tank_box[4];
		std::pair<float, float> wall_box[4];

		this->get_bounding_box(tank_box);
		w->get_bounding_box(wall_box);

		vec velocity = { x_vel,y_vel };

		float smallest_distance = 1000.0;
		int first_index_of_wall_box = 0;
		int index_of_closest_tank_corner = 0;

		for (int wall_index = 0; wall_index < 4; wall_index++)
		{
		for (int tank_corner_index = 0; tank_corner_index < 4; tank_corner_index++)
		{
		float distance = distance_line_point(
		v(wall_box[wall_index].first, wall_box[wall_index].second),
		v(wall_box[(wall_index + 1) % 4].first, wall_box[(wall_index + 1) % 4].second),
		v(tank_box[tank_corner_index].first, tank_box[tank_corner_index].second));
		if (distance < smallest_distance)
		{
		smallest_distance = distance;
		first_index_of_wall_box = wall_index;
		index_of_closest_tank_corner = tank_corner_index;
		}
		}
		}

		x -= x_vel;
		y -= y_vel;


		vec wall_first_point = v(wall_box[first_index_of_wall_box].first, wall_box[first_index_of_wall_box].second);
		vec wall_second_point = v(wall_box[(first_index_of_wall_box + 1)%4].first, wall_box[(first_index_of_wall_box + 1)%4].second);
		vec wall_vec = v((wall_first_point.x - wall_second_point.x), (wall_first_point.y - wall_second_point.y));

		vec projected = project(velocity, wall_vec);
		vec perp_projected = normalize(project(velocity, perp(wall_vec)));

		x -= smallest_distance * perp_projected.x;
		y -= smallest_distance * perp_projected.y;

		x += projected.x;
		y += projected.y;

		//x_vel = projected.x;
		//y_vel = projected.y;
		*/
	}
}

bool Tank::is_dead()
{
	return (!alive);
}