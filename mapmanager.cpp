#include "mapmanager.h"
void MapManager::destroy()
{
	if (instance) delete instance;
}
MapManager *MapManager::instance = 0;
MapManager* MapManager::get_instance()
{
	if (!instance)
	{
		instance = new MapManager;
	}
	return instance;
}
MapManager::MapManager()
{
	current_map = NULL;
}

MapManager::~MapManager()
{
	if (current_map) delete current_map;
}

void MapManager::set_map(Terrain* t)
{
	if (current_map) delete current_map;
	current_map = t;
}

