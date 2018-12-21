#include "Client.h"
#include "Account.h"

#include <string>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

namespace cx {
	namespace bank {
		namespace model {
			using namespace std;

			Client::~Client()
			{
				//cout << " ID : " << mId << endl;
			}
		}
	}
}