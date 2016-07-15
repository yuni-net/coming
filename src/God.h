#pragma once

namespace ProjectName
{
	class God
	{
	public:
		static void update();





	private:

		static God & get_instance();
		God();
		void update_dynamic();
		~God();





		God(const God & god);	// for singleton
		God & operator=(const God & god);	// for singleton
	};
}
