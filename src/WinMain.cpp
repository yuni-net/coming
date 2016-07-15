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
	displaym.context_color(1.0f, 1.0f, 1.0f);




	while (si3::Manager::begin_frame())
	{

		God::update();

		si3::Manager::show();


	}


	return 0;
}



