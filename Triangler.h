#pragma once

#include <memory>
#include <simplect3D.h>

class Triangler
{
public:
	Triangler();

	/*
	 * @return
	 *     true ... Triangler reached to screen.
	 *     false ... Triangler has not reached to screen.
	 */
	bool update();
	void die();
	bool am_I_dead() const;






private:
	std::unique_ptr<si3::Triangle> triangle;
	float calc_x() const;
	float calc_y() const;
	si3::Coor3 get_random() const;
	bool im_dead;
};