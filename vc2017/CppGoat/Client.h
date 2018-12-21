#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>
#include "Account.h"
namespace cx {
	namespace bank {
		namespace model {
			using namespace cx::bank::model;
			using namespace std;

			class Client
			{
			protected:
			public:
				std::string mId;
				std::string mName;
				std::string mBINumber;
				std::string mDateCreation;
				int mStatus;

				Client(std::string id = "", std::string name = "") : mId(id), mName(name)
				{
					mStatus = 0;
				}

				bool operator==(const Client & obj)
				{
					return (mId == obj.mId);
				}
				bool operator <(const Client & c) const
				{
					return mId < c.mId;
				}

				friend std::ostream & operator << (std::ostream &out, const Client & obj)
				{
					out << "'" << obj.mId << "','" << obj.mName << "','" << obj.mBINumber << "'," << obj.mStatus << ",'" << obj.mDateCreation << "'" << endl;
					return out;
				}

				friend std::istream & operator >> (std::istream &in, Client &obj)
				{
					in >> obj.mId;
					in >> obj.mName;
					in >> obj.mBINumber;
					in >> obj.mStatus;
					in >> obj.mDateCreation;
					return in;
				}

				struct ClientComparator
				{
					// Compare 2 Client objects using name
					bool operator ()(const Client & c1, const Client & c2)
					{
						if (c1.mName == c2.mName)
							return c1 < c2;
						return c1.mName < c2.mName;
					}
				};

				~Client();
			};
		}
	}
}
