#pragma once

namespace cx
{
	class BaseApplication
	{
	public:
		BaseApplication(int argc, char **argv);
		~BaseApplication();
		int run();
	};
}
