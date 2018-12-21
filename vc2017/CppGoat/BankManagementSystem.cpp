#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES  1
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#include "CpGoatDefines.h"
#include "BankManagementSystem.h"
#include "AdministrationService.h"
#include "Account.h"
#include <random>


#include <iostream>
using namespace std;

namespace cx {
	namespace bank {
		using namespace std;

		class x {
			const char *what()  const throw() { return string().c_str(); }

		};

		BankManagementSystem::BankManagementSystem()
		{
			//cout << ::Hugo << endl;
			this->accountService = std::make_unique<AccountService>();
			this->clientService = new ClientService;
		}

		BankManagementSystem::~BankManagementSystem()
		{
			cout << "Call BankManagementSystem::~BankManagementSystem()" << endl;
			//
			// delete the pointer : clientService
			//
			//delete clientService;
		}

		void BankManagementSystem::GetAllAccountInSystem()
		{
		}

		// Create Account
		//
		//
		void BankManagementSystem::CreateAccountInSystem()
		{
			Client client = GetClientInformationInputs();
			Account account = GetAccountInformationInputs();
			//account.accountId = StringGenerator();

			AccountOwner accountOwner;
			accountOwner.ownerId = client.mId;
			accountOwner.ownerName = client.mName;

			account.ownerId = client.mId;
			account.owners.push_back(&accountOwner);

			auto resultClient = this->clientService->createClient(&client);
			if (resultClient == nullptr) {
				cout << "Error at create client " << endl;
				return;
			}

			auto resultAccount = this->accountService->createAccount(&account);
			if (resultAccount == nullptr) {
				cout << "Error at create account " << endl;
				return;
				throw; // dead code
			}

			cout << "\n\t\tYour Account has Been Created. Success!" << endl;
		}

		void BankManagementSystem::GetAccountInfo(int accountNo)
		{
			Account* account = this->accountService->search(accountNo);
			if (account == nullptr) {
				// dead code
				return;
			}
			string clientId = "1";
			Client* clientResult = this->clientService->search(std::stoi(account->ownerId));
			if (clientResult == nullptr) {
				return;
			}

			cout << "\n\t\t#### Information for Account: " << account->accountId << " ### " << endl;
			cout << "\n\t\tClient Id \t : " << clientResult->mId << endl;
			cout << "\t\tName\t\t : " << clientResult->mName << endl;
			cout << "\t\tBI\t\t : " << clientResult->mBINumber << endl;
			cout << "\t\tCash Balance\t : " << account->GetBalance() <<" "<<account->typeCoin << endl;
			
			if (account !=nullptr)
				PrintTransactionHistory(account);			
		}


		void BankManagementSystem::PrintTransactionHistory(Account* acc)
		{

			std::list<Transaction> transactions = acc->transactions;
			if (transactions.size() == 0) {
				cout << "\n\t\t\t ### No movements in bank account... ###" << endl;
				return;
			}

			cout << "\n\t\t###Transaction History###\n" << endl;
			cout << "\t\t" << setw(15) << "Action" << setw(15) << "Amount" << setw(15) << "Cash Balance" << setw(15) << "Date Create\n" << endl;

			string action = string();
			for (auto trans : transactions) {
				if (trans.typeTrans == 0)
					action = "Deposit";
				else
					action = "Withdraw";
				//cout << "\t\t" << action << "\t\t" << trans.value << "\t\t" << trans.balance << "\t\t\t\t" << trans.date << endl;
				cout << "\t\t" << setw(15) << action << setw(15) << trans.value << setw(15) << trans.balance << setw(15) << trans.date << endl;
			}
		}

		void BankManagementSystem::TransactionHistory(int accountNo)
		{
			Account* account = this->accountService->search(accountNo);
			if (account == nullptr) {				
				return;
			}			
			PrintTransactionHistory(account);
		}

		void BankManagementSystem::GetClientInfo(int clientNo)
		{
			Client* result = this->clientService->search(clientNo);
			if (result != nullptr) {
				system("cls");
				cout << "\n\t\t#### Information for client: " << result->mId << " ### " << endl;
				cout << "\n\t\tId \t\t : " << result->mId << endl;
				cout << "\t\tName\t\t : " << result->mName << endl;
				cout << "\t\tBI\t\t : " << result->mBINumber << endl;
				cout << "\t\tCreate Date\t : " << result->mDateCreation << endl;
			}
			else {
				cout << "\n\t\tClient\t : " << clientNo << " not found in system" << endl;
			}
		}

		int BankManagementSystem::ModifyClientInfo(Client client)
		{
			Client *clientPrt = this->clientService->createClient();
			if (clientPrt = 0) {
				return 0;
			}
			return 0;
		}



		void BankManagementSystem::CancellationOfAccount(short nClient, int nAccount)
		{
			// Check the client

			this->clientService->deleteClient(1);
		}

		void BankManagementSystem::DepositMoney(int accounNo, double value)
		{
			Account* account = this->accountService->search(accounNo);
			if (account == nullptr) {
				// dead code
				cout << "Account does exist in system : " << accounNo << endl;
				delete account;
			}
			else
				this->accountService->deposite(accounNo, value);

			cout << "\n\tDeposit " << value << " to bank account : " << accounNo << endl;
		}

		void BankManagementSystem::DrawMoney(int accounNo, double value)
		{
			Account* account = this->accountService->search(accounNo);
			if (account == nullptr) {
				// dead code				
				cout << "Account does exist in system : " << accounNo << endl;
				return;
				delete account;
			}
			else
				this->accountService->withdraw(accounNo, value);

			cout << "\n\tDraw " << value << " form your bank account : " << accounNo << endl;
		}


		void BankManagementSystem::PrintBankOperation()
		{
			cout << "Operation: " << endl;
			cout << "Operation\t : " << endl;
			cout << "Balance\t : " << endl;
		}


		double BankManagementSystem::GetBalance(int accountNo)
		{
			//// Get Client
			//Client* client = nullptr;
			//client = this->clientService->search(clientNo);
			//if (std::is_null_pointer<decltype(client)>::value)
			//{
			//	cout << " Client not found : " << clientNo << endl;
			//	return 0.0f;
			//}
			// Get Account...
			Account* account = this->accountService->search(accountNo);
			if (account) {
				// dead code
				delete account;
				return 0.0f;
				throw exception(); //dead code
			}
			// The client have permissions in this account
			if (to_string(accountNo) == account->accountId) {
				//cout << "Balance : " << account->GetBalance() << endl;
				return account->GetBalance();
			}
			else
				throw exception();
		}

		//void BankManagementSystem::ListAllClient(int typeAlgorithm)
		//{
		//	this->accountService->display();
		//	this->clientService->displayClients();
		//}

		void BankManagementSystem::ClientBackup(string pathLocation)
		{
			// #########################################
			//
			// CWE-120: CWE-120: Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')
			//
			// CWE-121: Stack-based Buffer Overflow
			//
			//
			char filePath[BUFSIZEPATH];

			// Eliminating deprecation warnings
			// _CRT_SECURE_NO_WARNINGS where define
			// strcpy is a unsafe funtion
			// strcpy_s is a security enhanced version
			strcpy(filePath, pathLocation.c_str());
			this->clientService->MakeBackupClientsFile(filePath);
		}

		// ############ Client Data ##########################
		// #
		// #
		Client BankManagementSystem::GetClientInformationInputs()
		{
			Client c;
			try
			{
				cout << "\n\t### Client data ### \n" << endl;
				c.mId = StringGenerator();
				cout << "\tClient Id \t\t: " << c.mId;
				//cin >> c.mId;
				// ##############################
				//
				// Common String Manipulation Errors
				//
				// C++ Unbounded Copy
				//
				// Inputting more than 8 characters into following the
				// C++ program results in an out - of - bounds write
				//
				string name;
				cout << "\n\tEnter Client Name \t: ";	
				cin >> name;
				c.mName = name;
				// #########################################
				//
				// Solution for C++ Unbounded Copy
				//
				const int MAX = 10;
				char BI[MAX];
				//
				// Using the std::setw or cin.width
				//
				//
				cout << "\n\tEnter Client BI \t: ";
				cin >> setw(MAX) >> BI;
				c.mBINumber = string(BI);
				c.mDateCreation = string();
				c.mStatus = 0;
			}
			catch (exception ex)
			{
				throw exception(ex);
			}

			return c;
		}

		Account BankManagementSystem::GetAccountInformationInputs()
		{
			Account a;

			cout << "\n\t### Account data ### \n" << endl;
			a.accountId = StringGenerator();
			cout << "\tAccount Id \t\t: " << a.accountId;

			cout << "\n\tType Account \t\t: ";
			cin >> a.accountModalidade;

			cout << "\tCoin \t\t\t: ";
			cin >> a.typeCoin;

			string _balance;
			cout << "\tDeposite \t\t: ";
			cin >> _balance;			
			a.balance = strtof(_balance.c_str(), 0);
			return a;
		}
		
	}
}