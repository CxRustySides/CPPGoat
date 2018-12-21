#include "Account.h"
namespace cx {
	namespace bank {
		namespace model {
			Account::Account()
			{
			}

			Account::~Account()
			{
			}

			void Account::display() const
			{
			}

			void Account::executeTransation(Transaction* trans)
			{
				if (trans->typeTrans == 0) {
					this->balance += trans->value;
				}
				else if (trans->typeTrans == 1) {
					this->balance -= trans->value;
				}
				trans->balance = this->balance;				

				Transaction a;
				a.accountId = trans->accountId;
				a.balance = trans->balance;
				a.transNumber = trans->transNumber;
				a.typeTrans = trans->typeTrans;
				a.date = trans->date;
				a.value = trans->value;

				this->transactions.push_front(a);
			}
			float Account::GetBalance() const
			{
				return balance;
			}
		}
	}
}