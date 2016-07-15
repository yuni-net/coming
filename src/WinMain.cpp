#include <simplect3D.h>
#include "God.h"

using namespace ProjectName;

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	fw::xrandom_init(static_cast<unsigned long>(time(NULL)));

	if (si3::Manager::init(960, 600) == false)
	{
		fw::popup("failed");
		return -1;
	}

	auto & displaym = si3::Manager::display_manager();
	displaym.context_color(0.68f, 1.0f, 1.0f);

	auto & skydome = si3::Manager::display_manager().get_skydome();
	skydome.load("data/sky.jpg");

	auto & camera = si3::Manager::camera();
	camera.x(0.0f);
	camera.y(00.0f);
	camera.z(-12.0f);

	camera.look_x(0.0f);
	camera.look_y(0.0f);
	camera.look_z(0.0f);


	while (si3::Manager::begin_frame())
	{

		God::update();

		si3::Manager::show();


	}


	return 0;
}



