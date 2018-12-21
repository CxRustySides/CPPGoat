#pragma once
#include <string>
#include <vector>
#include <list>
#include <map>
#include <string>

namespace cx {
	namespace bank {
		namespace model {

			using namespace std;

			class Account1
			{
			private:
				unsigned long accountId;
				string nib;
				string name;
				float balance;
				char accountType;

			public:
				Account1();
				Account1(const string&, const string&);
				~Account1();
				void Deposit(int);
				void Draw(int);
				float Balance() const;
				char AccountType() const;
				void AccountType(char type);
				int GetAccountNo() const;
				void AccountNo(int);
				void Name(const string&);
				string& Name();
				void Nib(const string&);
				string& Nib();
			};
		}
	}
}
