#pragma once
namespace cx {
	namespace bank {
		using namespace std;

		class IBankManagmentSystemBase
		{
		public:
			IBankManagmentSystemBase();
			~IBankManagmentSystemBase();
			virtual int SystemLogin(char name, char password) = 0;
		};
	}
}
