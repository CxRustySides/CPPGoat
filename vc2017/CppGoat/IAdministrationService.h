#pragma once
namespace cx {
	namespace services {
		namespace admin {
			class IAdministrationService
			{
			public:
				virtual void display() = 0;
			};
		}
	}
}