#include "hijackingweapon.h"
#include "slug.h"
HijackingWeapon::HijackingWeapon()
{
	hijacks = true;
	currently_hijacking = false;
}

bool HijackingWeapon::is_currently_hijacking()
{
	return currently_hijacking;
}