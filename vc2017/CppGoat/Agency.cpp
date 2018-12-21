#include "Agency.h"

namespace cx {
	namespace bank {
		namespace model {
			using namespace std;

			Agency::Agency()
			{
			}
			Agency::~Agency()
			{
			}

			void Agency::SetAgencyName(string _agencyName)
			{
				agencyName = _agencyName;
			}

			std::string Agency::GetAgencyName() const
			{
				return agencyName;
			}
		}
	}
}