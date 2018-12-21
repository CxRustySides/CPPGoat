#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include "ClientService.h"
#include "AccountService.h"
#include "AccountService.h"

namespace cx {
	namespace services {
		namespace bank {

			using namespace std;
			using namespace cx::services::admin;
			using namespace cx::services::account;
			using namespace cx::services::client;

			class IBankManagementSystemService
			{
			protected:
				// Services
				std::unique_ptr<AccountService> accountService;
				ClientService* clientService;
			public:
			};
		}
	}
};
