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
#include  <limits.h>;
#include "BankManagementSystem.h"
#include "IBankManagmentSystemBase.h"
#include "BaseApplication.h"
#include "Account.h"
#include "Client.h"

using namespace cx::bank;
using namespace std;
using namespace cx::bank::model;





int main2(int argc, char** argv)
{
	auto bank = new BankManagementSystem("");

	//// Create Account
	//Account account;
	//bank->CreateAccountInSystem(account);
	//bank->GetAccountInfo(1);
	//bank->ModifyAccountInfo(1, &account);

	//// Client operation
	//Client client;
	//bank->CreateClientInSystem(client);
	//bank->GetClientInfo(1);
	//bank->ModifyClientInfo(client);
	/*Client c;
	bank->CreateClientInSystem(c);*/

	//bank->GetBalance(10); // accountNo
	std::cout << "Balance : " << bank->GetBalance(1); // client --- account

	std::cout << "\n" << endl;
	//bank->ListAllClient(0);

	// CWE-121: Stack-based Buffer Overflow
	//string pathLocation2 = "..\\..\\Data\\backup\\ClientBackup.txt && more ..\\..\\Data\\backup\\ClientBackup.txt";
	string pathLocation = "..\\..\\Data\\backup\\ClientBackup.txt";
	int withStackOverflow = 0;
	bank->ClientBackup(pathLocation, 0);
	// Client

	system("pause");

	return 0;
}

//
//
//
//
//void intro()
//{
//	cout << "\n\n\n\t  BANK";
//	cout << "\n\n\tMANAGEMENT";
//	cout << "\n\n\t  SYSTEM";
//	cin.get();
//}
//
//Account GetInputAccount()
//{
//	char type = '\0';
//	Account c;
//	cout << "\nEnter The account No. :";
//	int id;
//	cin >> id;
//	c.AccountNo(id);
//	cout << "\nEnter the name of client : ";
//	cin.ignore();
//	string name = "";
//	getline(cin, name);
//	c.Name(name);
//	cout << "\nEnter Type of The account (C/S) : ";
//	cin >> type;
//	c.AccountType(type);
//
//	return c;
//}
//
//void DisplayAccount(Account c)
//{
//	cout << "\nAccount No. : " << c.GetAccountNo();
//	cout << "\nAccount Holder Name : ";
//	cout << c.Name();
//	cout << "\nType of Account : " << c.AccountType();
//	cout << "\nBalance amount : " << c.Balance();
//}
//
//
//
//int main2(int argc, char** argv)
//{
//	auto bank = new BankManagementSystem();
//
//	Account ap;
//	char ch;
//	int num;
//	do
//	{
//		system("cls");
//		cout << "\n\n\n\tMAIN MENU";
//		cout << "\n\n\t01. NEW ACCOUNT";
//		cout << "\n\n\t02. DISPLAY AMOUNT";
//		cout << "\n\n\t02. DEPOSIT AMOUNT";
//		cout << "\n\n\t03. WITHDRAW AMOUNT";
//		cout << "\n\n\t04. BALANCE ENQUIRY";
//		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
//		cout << "\n\n\t06. CLOSE AN ACCOUNT";
//		cout << "\n\n\t07. MODIFY AN ACCOUNT";
//		cout << "\n\n\t08. EXIT";
//		cout << "\n\n\tSelect Your Option (1-8) ";
//		cin >> ch;
//		system("cls");
//		switch (ch)
//		{
//		case '1':
//			ap = GetInputAccount();
//			DisplayAccount(ap);
//			cout << "\n\nConfirme the information (Y/N) :";
//			char ok;
//			cin >> ok;
//			if (ok == 'Y') {
//				bank->CreateAccount(ap);
//			}
//			break;
//		case '2':
//			cout << "\nEnter The account No. :";
//			int id;
//			cin >> id;
//			DisplayAccount(bank->FindAccount(id));
//			break;
//		default:cout << "a";
//		}
//		cin.ignore();
//		cin.get();
//	} while (ch != '8');
//
//	delete bank;
//
//	return 0;
//}