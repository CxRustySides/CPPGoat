#include "Account.h"
//#include "StreamRecord.h"
//#include "DatabaseRecord.h"
#include "Record.h"
namespace cx {
	namespace services {
		namespace account {

			using namespace std;
			using namespace cx::bank::model;
			using namespace cx::bank::dal;

			class AccountService1
			{
			private:

				int ExistAccount(int accNo);

			public:
				AccountService1();
				virtual ~AccountService1();
				void CreateAccount(Account1& account);
				Account1 FindAccount(int);
				//virtual Account FindAccount(const string&) = 0;
				int SaveAccount(Account1& account);
				int ModifiAccount(Account1&);

				

				const std::string& AccountFile()
				{
					// Initialize the static variable
					static std::string foo("account.dat");
					return foo;
				}
			};
		}
	}
}