#include "Account1.h"
#include <string>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

namespace cx {
	namespace bank {
		namespace model {
			Account1::Account1()
			{
				name = string();
				name = string();
				accountId = -1;
				accountType = '1';
			}
			Account1::Account1(const string & _name, const string & _nib) : Account1()
			{
				name = _name;
				nib = _nib;
			}

			Account1::~Account1()
			{
			}

			void Account1::Deposit(int dep)
			{
				balance += dep;
			}

			void Account1::Draw(int draw)
			{
				balance -= draw;
			}

			float Account1::Balance() const
			{
				return balance;
			}

			char Account1::AccountType() const
			{
				return this->accountType;
			}

			void Account1::AccountType(char type)
			{
				this->accountType = type;
			}

			int Account1::GetAccountNo() const
			{
				return this->accountId;
			}
			void Account1::AccountNo(int accId)
			{
				this->accountId = accId;
			}

			void Account1::Name(const string &_name)
			{
				this->name = _name;
			}
			string& Account1::Name()
			{
				return this->name;
			}

			void Account1::Nib(const string &_nib)
			{
				this->nib = _nib;
			}
			string& Account1::Nib()
			{
				return this->nib;
			}
		}
	}
}