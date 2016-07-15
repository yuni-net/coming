#include <simplect3D.h>

#include "God.h"

namespace ProjectName
{
	void God::update()
	{
		get_instance().update_dynamic();
	}




	God & God::get_instance()
	{
		static God god;
		return god;
	}

	God::God()
	{
		// todo
	}

	void God::update_dynamic()
	{
		// todo
	}

	God::~God()
	{
		// todo
	}

}