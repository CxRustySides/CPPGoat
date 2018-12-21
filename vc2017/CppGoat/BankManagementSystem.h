#pragma once

#include "AccountService.h"
#include "IAdministrationService.h"
#include "IBankManagementSystemService.h"
#include "Account.h"
#include "Client.h"
#include "Agency.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <memory>
#include <string>
#include<iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <list>
#include <ctime>
#include <random>
#include <iostream>

namespace cx {
	namespace bank {
		using namespace std;
		using namespace cx::bank::model;
		using namespace cx::services::admin;
		using namespace cx::services::account;
		using namespace cx::services::bank;

		enum {
			AGENCIES = 2
		};

		class BankManagementSystem : IBankManagementSystemService
		{
		private:
			Agency agency[AGENCIES] = {};
			string bankName;
			Agency* currentAgency;			

			// Account

			// Client functions
			Client GetClientInformationInputs();
			Account GetAccountInformationInputs();

			void PrintBankOperation();

			void PrintTransactionHistory(Account* acc);

		public:

			BankManagementSystem(string _bankName = string()) : bankName(_bankName) {
				this->accountService = std::make_unique<AccountService>();
				this->clientService = new ClientService;
			}

			BankManagementSystem();
			~BankManagementSystem();

			void GetAllAccountInSystem();
			void CreateAccountInSystem();
			void GetAccountInfo(int accountNo);
			void TransactionHistory(int accountNo);

			//void LoadDataToMemoryFromFile();
			//void ModifyAccountInfo(int accountNo, Account* accpunt);
			//void DisplayClientInformation();

			// Client
			void GetClientInfo(int clientNo);
			int ModifyClientInfo(Client c);
			//void ListAllClient(int typeAlgorithm);
			void ClientBackup(string pathLocation);

			double GetBalance(int accountNo);

			void CancellationOfAccount(short nClient, int nAccount);

			// Operator Operations
			void DepositMoney(int accounNo, double value);
			void DrawMoney(int accounNo, double value);

			/*void MakeDeposit(string accounNo, double value);
			void DrawMoney(string accounNo, double value);*/

			//......

			std::string StringGenerator()
			{
				std::random_device dev;
				std::mt19937 engine(dev());
				return std::to_string(engine()).substr(0,5);
			}

			std::string StringGeneratorBad()
			{
				std::time_t t;
				std::mt19937 engine(std::time(&t));

				return std::to_string(engine());
			}

			std::string StringGeneratorBadV2()
			{
				std::mt19937 engine;
				return std::to_string(engine());
			}
		};
	}
}