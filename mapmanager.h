#pragma once
#include "terrain.h"
#include "default_terrain.h"

class MapManager
{
private:
	Terrain* current_map;
	static MapManager *instance;

public:
	static MapManager *get_instance();
	static void destroy();
	MapManager();
	~MapManager();
	Terrain* get_current_map() { return current_map; }
	void set_map(Terrain* t);
};