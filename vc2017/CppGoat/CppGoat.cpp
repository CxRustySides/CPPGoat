// CppGoat.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#include "BankManagementSystem.h"

using namespace cx::bank;
using namespace std;

int main()
{
	char ch;
	//int num;
	int menuSelection = 0;
	auto bank = new BankManagementSystem("");

	do
	{
		system("cls");
		cout << "\n" << endl;
		cout << "\t\t\t\tWelcome to the Bank Management System" << endl;

		cout << "\n\n\t01. Open An Account";
		cout << "\n\n\t02. View Account Information";
		cout << "\n\n\t03. Deposit to account";
		cout << "\n\n\t04. Withdraw from account";
		cout << "\n\n\t05. Display transactions history";
		cout << "\n\n\t06. Client Backup";
		cout << "\n\n\t07. Client Backup(Command Injection)";
		cout << "\n\n\t08. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		cin >> ch;

		system("cls");

		int nAccId = -1;
		string s = "";
		std::string first;

		switch (ch)
		{
		case '1':
			bank->CreateAccountInSystem();
			break;
		case '2':
			int nId;
			cout << "\n\tAccount Id : ";
			cin >> nId;
			system("cls");
			bank->GetAccountInfo(nId);
			break;
		case '3':
			cout << "\n\tAccount Id : ";
			cin >> nAccId;
			int depositMoney;
			cout << "\tMoney to deposit : ";
			cin >> depositMoney;
			system("cls");
			bank->DepositMoney(nAccId, depositMoney);
			break;
		case '4':
			cout << "\n\tAccount Id : ";
			cin >> nAccId;
			int drawMoney;
			cout << "\tAmount to withdraw : ";
			cin >> drawMoney;
			system("cls");
			bank->DrawMoney(nAccId, drawMoney);
			break;
		case '5':
			cout << "\n\tAccount Id : ";
			cin >> nAccId;
			system("cls");
			bank->TransactionHistory(nAccId);
			break;
		case '6':
			cout << "\n\tPath: c:\\temp\\t.txt";			
			bank->ClientBackup("c:\\temp\\t.txt");
			break;
		case '7':
			cout << "\n\tPath: c:\\temp\\t.txt & more c:\\temp\\t.txt";
			bank->ClientBackup("c:\\temp\\t.txt & more c:\\temp\\t.txt");
			break;
		default:
			cout << "\n\n\tThanks for using bank management system" << endl;
			cout << "\\tEnd the program " << endl;
		}

		cin.ignore();
		cin.get();
	} while (ch != '8');

	delete bank;

	//system("pause");

	return 0;
}