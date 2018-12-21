#pragma once
#include "Record.h"
#include <cassert>
#include <iostream>
#include <string>
namespace cx {
	namespace bank {
		namespace dal {
			using namespace std;

			class MySql {};

			class DatabaseRecord : public Record
			{
			public:
				DatabaseRecord() : m_dbConnection(new MySql) {}

				void StartRecord() { cout << "start transaction\n"; }

				void StoreField(const string &key, const string &value)
				{
					cout << "insert into table\n";
					cout << "key : " << key << endl;
					cout << "Value : " << value << endl;
				}
				void FinishRecord() { cout << "finish transaction\n"; }

			private:
				MySql * m_dbConnection;
			};
		}
	}
}