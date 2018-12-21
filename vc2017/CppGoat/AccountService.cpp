#include "AccountService.h"
#include "Global.h"
#include <cassert>
#include <iostream>
#include <string>
#include <direct.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include<cmath>
#include <ctime>
using namespace std;

namespace cx {
	namespace services {
		namespace account {


			AccountService::AccountService()
			{
				LoadData();
			}

			AccountService::~AccountService()
			{
			}

			Account * AccountService::createAccount(Account * acc)
			{
				Account c = *acc;
				c.accountStatus = -1;
				std::ofstream outFile("..\\..\\Data\\db\\Account.txt", std::ofstream::app);
				outFile << c.accountId << "," << c.ownerId << "," << c.balance << "," << c.typeCoin  << "," << c.accountModalidade << "," << c.accountStatus << "\n";

				this->accountInSystem.push_back(c);
				return acc;
			}

			void AccountService::deposite(int accNo, float value)
			{
				// Exist account in system
				Account* acc = search(accNo);
				if (acc == nullptr) {
					cout << "Account not exist in system" << endl;
					return;
				}

				Transaction trans = CreateTransaction(accNo, value);
				trans.accountId = acc->accountId;
				trans.typeTrans = 0;
				acc->executeTransation(&trans);
			}

			void AccountService::withdraw(int accNo, float value)
			{
				// Exist account in system
				Account* acc = search(accNo);

				Transaction trans = CreateTransaction(accNo, value);
				trans.accountId = acc->accountId;
				trans.typeTrans = 1;

				acc->executeTransation(&trans);
			}

			Account* AccountService::search(int accNumber)
			{
				Account* acc = nullptr;

				string scNo = std::to_string(accNumber);

				const auto id_equal = [scNo](const Account p)
				{ return p.accountId == scNo; };

				auto iter = std::find_if(this->accountInSystem.begin(), this->accountInSystem.end(), id_equal);

				if (iter != this->accountInSystem.end()) {
					acc = &*iter;
				}
				else {
					/* not found */
				}
				return acc;
			}

			void AccountService::display(string& accNo)
			{
				Account* acc = search((int)accNo.c_str());
				cout << "Print Account information " << endl;
				acc->display();
			}

			Transaction AccountService::CreateTransaction(int accNo, int value)
			{
				Transaction trans;
				time_t t = time(NULL);
				tm* timePtr = localtime(&t);
				string dt = std::to_string((timePtr->tm_mday)) + "/" + std::to_string((timePtr->tm_mon) + 1) + "/" + std::to_string((timePtr->tm_year) + 1900);
				trans.date = dt;
				trans.transNumber = StringGenerator();;
				trans.value = value;
				return trans;
			}

			void AccountService::LoadData()
			{
				const string filePathAccount = "..\\..\\Data\\db\\Account.txt";
				std::ifstream input_file(filePathAccount);
				std::string str = string();

				while (std::getline(input_file, str))
				{
					std::vector<std::string> words;
					split(str, words, ',');
					Account c;
					c.accountId = words[0];
					c.ownerId = words[1];
					c.balance = std::stof(words[2]);
					c.accountModalidade = words[3];
					c.typeCoin = words[4];
					c.accountStatus = std::stoi(words[5]);
					this->accountInSystem.push_back(c);
				}

				std::list<Transaction> transactions;
				const string filePathTransaction = "..\\..\\Data\\db\\Transaction.txt";
				std::ifstream inputFileTransaction(filePathTransaction);
				
				while (std::getline(inputFileTransaction, str))
				{
					std::vector<std::string> words;
					split(str, words, ',');
					Transaction c;
					c.accountId = words[0];
					c.transNumber = words[1];
					c.typeTrans = std::stof(words[2]);
					c.value = std::stod(words[3]);
					c.balance = std::stof(words[4]);
					c.date = words[5];
					transactions.push_front(c);
				}
			}
		}
	}
}