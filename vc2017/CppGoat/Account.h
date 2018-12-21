#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>

namespace cx {
	namespace bank {
		namespace model {
			using namespace std;

			typedef enum AccountMoeda
			{
				EURO,
				DOLLAR,
			}AccountMoeda;

			typedef enum AccountModalidade
			{
				ORDER,
				TERM
			}AccountModalidade;

			typedef enum AccountType
			{
				JOIN,
				SHARED

			}AccountType;

			struct Transaction
			{
				std::string accountId;
				std::string transNumber;
				double value;
				float balance;
				std::string date;
				int typeTrans;
				string transStatus;
			};

			struct AccountOwner
			{
				std::string ownerId;
				std::string ownerName;
			};

			class Account
			{
			public:
				std::string accountId;
				std::string ownerId;
				float balance;

				std::string accountModalidade;
				std::string typeCoin;				
				int accountStatus;

				std::list<AccountOwner*> owners;
				std::list<Transaction> transactions;
				void display() const;
				void executeTransation(Transaction* trans);
				float GetBalance() const;
				Account();
				~Account();
			};
		}
	}
}
