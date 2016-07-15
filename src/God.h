#pragma once

#include <memory>
#include "../Triangler.h"

namespace ProjectName
{
	class God
	{
	public:
		static void update();





	private:
		enum State
		{
			game_playing,
			game_over
		};

		State state;

		std::unique_ptr<Triangler> triangler;

		static God & get_instance();
		God();
		void update_dynamic();
		~God();





		God(const God & god);	// for singleton
		God & operator=(const God & god);	// for singleton
		bool judge();
	};
}
