#pragma once
class Controls
{
private:
	int forward;
	int reverse;
	int left;
	int right;
	int fire;
public:
	Controls(int _for, int _rev, int _lef, int _rig, int _fir);
	int get_forward() { return forward; }
	int get_reverse() { return reverse; }
	int get_left() { return left; }
	int get_right() { return right; }
	int get_fire() { return fire; }
	Controls();
};
