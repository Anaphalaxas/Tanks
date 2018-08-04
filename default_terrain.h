#pragma once
#include "terrain.h"

class DefaultTerrain : public Terrain
{
public:
	DefaultTerrain() : Terrain("resources/terrain.bmp") { cof = 0.04; }
};