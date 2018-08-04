#pragma once
#include <vector>
#include <algorithm>
class Tickable
{
public:
	virtual void tick() = 0;
	Tickable();
	~Tickable();
	static std::vector<Tickable*> tickables;

};

