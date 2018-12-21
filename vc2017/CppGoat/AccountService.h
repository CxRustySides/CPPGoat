#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <random>

#include "Account.h"
#include "TemplatesUtils.h"

namespace cx {
	namespace services {
		namespace account {
			using namespace cx::bank::model;

			class AccountService
			{
			private:
				void LoadData();
				std::list<Account> accountInSystem;
				Transaction CreateTransaction(int accNo, int value);
			public:
				AccountService();
				~AccountService();
				void deposite(int accNo, float value);
				void withdraw(int accNo, float value);
				Account* search(int accno);
				Account* createAccount(Account* acc);
				void display(string &accNo);

				std::string StringGenerator()
				{
					std::random_device dev;
					std::mt19937 engine(dev());
					return std::to_string(engine());
				}
			};
		}
	}
}
