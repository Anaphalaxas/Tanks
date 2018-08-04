#pragma once
#include "drawable.h"
class Terrain : public Drawable
{
protected:
	float cof; // Coefficient of friction
public:
	Terrain(const char* _image);
	float get_cof() { return cof; }
};
