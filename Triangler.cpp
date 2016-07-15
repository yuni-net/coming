#include "Triangler.h"

static const float beg_z = 100.0f;
static const float speed = 1.0f;

Triangler::Triangler()
{
	si3::Coor3 a(calc_x(), calc_y(), beg_z);
	si3::Coor3 b(calc_x(), calc_y(), beg_z);
	si3::Coor3 c(calc_x(), calc_y(), beg_z);
	triangle.reset(new si3::Triangle(a, b, c));
}

bool Triangler::update()
{
	triangle->z += speed;
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
	return 11 * ((fw::xrandom() % 20000)-10000) / 10000.0f;
}
float Triangler::calc_y() const
{
	return 7 * ((fw::xrandom() % 20000) - 10000) / 10000.0f;
}
