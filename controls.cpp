#include "controls.h"

Controls::Controls(int _for, int _rev, int _lef, int _rig, int _fir)
{
	forward = _for;
	reverse = _rev;
	left = _lef;
	right = _rig;
	fire = _fir;
}

Controls::Controls()
{

}