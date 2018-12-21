#pragma once
#include <string>

namespace cx {
	namespace bank {
		namespace model {

			using namespace std;
			class Agency
			{
			private:
				string agencyName;
				short int agencyNumber;
			public:
				Agency();
				~Agency();
				void SetAgencyName(std::string  _bankName);
				std::string  GetAgencyName() const;
			};
		}
	}
}
