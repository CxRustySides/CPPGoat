#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "Client.h"
#include "TemplatesUtils.h"

namespace cx {
	namespace services {
		namespace client {
			using namespace std;
			using namespace cx::bank::model;

			class ClientService
			{
#ifdef _WIN32
				const string FILE_OF_CLIENTS = "..\\..\\Data\\db\\Client.txt";
				const string FILE_OF_CLIENTS_V2 = "..\\..\\Data\\db\\Client_V2.txt";
#endif
#ifdef __unix__
				const string FILE_OF_CLIENTS = "../../Data/db/Client.txt";
#endif
			private:
				std::list<Client> clients;
				void LoadData();

			public:
				ClientService();
				virtual ~ClientService();
				Client* search(int cNo);
				Client* createClient();
				Client* createClient(Client* c);
				int modifyClientInfo(Client c);
				int deleteClient(int cNo);

				void MakeBackupClientsFile(char * filePath);

				void exportClientToCSV(string filePath = string());
				void importClientFromCSV(string filePath = "");

				void displayClients();
			};
		}
	}
}
