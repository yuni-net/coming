#include "Triangler.h"

static const float beg_z = 100.0f;
static const float speed = 0.6f;

Triangler::Triangler()
{
	si3::Coor3 a = get_random();
	si3::Coor3 b = get_random();
	si3::Coor3 c = get_random();
	triangle.reset(new si3::Triangle(a, b, c));
	triangle->x = 0.0f;
	triangle->y = 0.0f;
	triangle->z = beg_z;
}

bool Triangler::update()
{
	triangle->z -= speed;
	if (triangle->z <= 0.0f)
	{
		triangle->z = 0.0f;
		si3::Manager::register_display_object(*triangle);
		return true;
	}

	si3::Manager::register_display_object(*triangle);
	return false;
}


float Triangler::calc_x() const
{
	return 11 * (static_cast<int>(fw::xrandom() % 20000)-10000) / 10000.0f;
}
float Triangler::calc_y() const
{
	return 7 * (static_cast<int>(fw::xrandom() % 20000) - 10000) / 10000.0f;
}


si3::Coor3 Triangler::get_random() const
{
	si3::Coor3 coor;
	coor.z = 0.0f;
	int type = fw::xrandom() % 4;
	if (type==0)
	{
		coor.x = 11.0f;
		coor.y = calc_y();
	}
	else if (type == 1)
	{
		coor.x = -11.0f;
		coor.y = calc_y();
	}
	else if (type == 2)
	{
		coor.x = calc_x();
		coor.y = 7.0f;
	}
	else if (type == 3)
	{
		coor.x = calc_x();
		coor.y = -7.0f;
	}
	return coor;
}