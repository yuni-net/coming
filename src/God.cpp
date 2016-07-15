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
		state = State::game_playing;
		triangler.reset(new Triangler());
		// todo
	}

	void God::update_dynamic()
	{
		if (state == State::game_playing)
		{
			if (triangler->am_I_dead())
			{
				triangler.reset(new Triangler());
			}
			const bool todo_judge = triangler->update();
			if (todo_judge == false)
			{
				return;
			}
			
			const bool did_collide = judge(*triangler);
			if (did_collide)
			{
				state = State::game_over;
			}
			else
			{
				triangler->die();
			}
		}
		else
		{

		}
	}

	God::~God()
	{
		// todo
	}

	bool God::judge(const Triangler & triangler)
	{
		return false;
	}
}