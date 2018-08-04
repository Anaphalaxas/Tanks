#pragma once
#include "tank.h"

class GreenTank : public Tank
{
public:
	GreenTank(float _x, float _y, float _rotation) : Tank(_x,_y,_rotation,"resources/tank_green.bmp"){}
};