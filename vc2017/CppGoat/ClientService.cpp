#include "ClientService.h"
#include "CSVWriter.h"
#include "StringUtils.h"
#include <direct.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include<cmath>
#include <ctime>

using namespace std;

namespace cx {
	namespace services {
		namespace client {
			using namespace cx::util;

			ClientService::ClientService()
			{
				LoadData();
			}

			ClientService::~ClientService()
			{
			}

			Client* ClientService::search(int cNo)
			{
				Client* client = nullptr;

				string scNo = intToString(cNo);

				const auto id_equal = [scNo](const Client p)
				{ return p.mId == scNo; };

				auto iter = std::find_if(this->clients.begin(), this->clients.end(), id_equal);

				if (iter != this->clients.end()) {
					client = &*iter;
				}
				else {
					/* not found */
				}
				return client;
			}

			int ClientService::deleteClient(int cNo)
			{
				Client* client = search(cNo);
				client->mStatus = 0;
				return 0;
			}

			void ClientService::MakeBackupClientsFile(char *filePath)
			{
				// outputdir = "..\\..\\Data\\backup\\Client.txt && more ..\\..\\Data\\backup\\Client.txt";

				// ######################################################
				//
				// CWE-404: Code Injection
				//
				// Exemple
				//cmd "..\\..\\Data\\backup\\Client.txt && more ..\\..\\Data\\backup\\Client.txt";

				string outputdir = "";
				if (filePath == '\0')
					outputdir = "..\\..\\Data\\db\\Client.txt";
				else
					outputdir = filePath;

				string cmd = "copy " + FILE_OF_CLIENTS + " " + outputdir;
				const char *command = cmd.c_str();
				int result = system(command);
				if (!result) {
					cout << " Command success : " + cmd << endl;
				}
				else {
					cout << " Command failed : " + cmd << endl;
				}
			}

			void ClientService::exportClientToCSV(string filePath)
			{
				std::vector<std::string> v{ "one", "two", "three" };
				std::ofstream outFile(FILE_OF_CLIENTS_V2);
				// the important part
				for (const auto &e : v) {
					outFile << e << "\n";
				}
			}

			void ClientService::importClientFromCSV(string filePath)
			{
				std::ifstream input_file(filePath);
				std::string str = string();
				try {
					while (std::getline(input_file, str))
					{
						// Process str
						std::vector<std::string> words;
						split(str, words, ',');
						Client c;
						c.mId = words[0];
						c.mName = cx::util::to_upper(words[1]);
						c.mBINumber = words[2];
						c.mStatus = atoi(words[3].c_str());
						c.mDateCreation = words[4];
						c.mName = cx::util::to_lower(c.mName); // duplicate line ...
						this->clients.push_back(c);
					}
				}
				catch (std::exception) {
					throw exception(); // exception
				}				
				// ######################################################
				//
				// CWE-404: Improper Resource Shutdown or Release
				//
				input_file.close();
			}

			void ClientService::displayClients()
			{
				this->clients.sort();

				// Sorting List using Lambda function as comparator
				this->clients.sort([](const Client & c1, const Client & c2)
				{
					if (c1.mName == c2.mName)
						return c1 < c2;
					return c1.mName < c2.mName;
				});

				this->clients.sort(Client::ClientComparator());

				std::cout << "\n\Id " << " \t\t  " << " Name " << " \t\t  " << " Status " << std::endl;

				std::for_each(this->clients.begin(), this->clients.end(),
					[](const Client & client)
				{
					//Print the contents
					std::cout << client.mId << " \t\t " << client.mName << " \t\t " << client.mStatus << std::endl;
				});
			}

			Client * ClientService::createClient()
			{
				Client client("1", "Hugo Filipe");
				/*client.mDateCreation = "28/03/2018";
				client.mBINumber = "96451231841";*/
				return &client;
			}

			Client* ClientService::createClient(Client* client)
			{
				if (client == 0)
					return nullptr;

				time_t t = time(NULL);
				tm* timePtr = localtime(&t);
				string dt = std::to_string((timePtr->tm_mday)) + "/" + std::to_string((timePtr->tm_mon) + 1) + "/" + std::to_string((timePtr->tm_year) + 1900);
				client->mDateCreation = dt;
				client->mStatus = 1;

				std::ofstream outFile(FILE_OF_CLIENTS, std::ofstream::app);
				outFile << client->mId << "," << client->mName << "," << client->mBINumber << "," << client->mStatus << "," << client->mDateCreation << "\n";

				this->clients.push_back(*client);

				return client;
			}

			int ClientService::modifyClientInfo(Client c)
			{
				return 0;
			}

			void ClientService::LoadData()
			{
				importClientFromCSV(FILE_OF_CLIENTS);

				//MakeBackupClientsFile(string().c_str());
				/*Client c("1", "Hugo Filipe");
				Client c1("7", "Hugo Filipe");
				Client c2("5", "Hugo Filipe");
				Client c3("4", "Hugo Filipe");
				Client c4("2", "Hugo Filipe");

				this->clients.push_back(c);
				this->clients.push_back(c1);
				this->clients.push_back(c2);
				this->clients.push_back(c3);
				this->clients.push_back(c4);*/
			}
		}
	}
}