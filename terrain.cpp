#include "terrain.h"
Terrain::Terrain(const char* _image) : Drawable(_image, 0)
{
	cx = 0;
	cy = 0;
	rotation = 0;
	x = 0;
	y = 0;
	cof = 0;
}